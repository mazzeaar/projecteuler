#include <iostream>
#include <chrono>
#include <iomanip>

/*
 * --------------------------------
 * Problem: '144'
 * https://projecteuler.net/problem=144
 * --------------------------------
 * @amazzetta
 *
 * ################################
 * #  Problem 144
 * #  Solved in: 11 µs (0 ms)
 * #  Solution: 354
 * ################################
 */

void print(double runtime, long int solution = 0)
{
    if ( solution == 0 )
    {
        std::cout << "\nSolution to problem 144 is not implemented yet!\n\n";
        return;
    }

    std::cout << "\n################################\n"
        << "#  Problem 144\n"
        << "#  Solved in: " << std::fixed << std::setprecision(0) << runtime << " µs (" << runtime / 1000 << " ms)\n"
        << "#  Solution: " << solution << "\n"
        << "################################\n";
}

// --------------------------------

/*
- starting from (0.0, 10.1)
    - first impact @ (1.4, -9.6)

- ellipse with shape 4x^2 + y^2 = 100
    - slope of tangent line at (x, y) := m = -4x/y

- how many bounces until exiting again?
    -> exiting when -0.01 <= x <= 0.01

p2 - p1 = point to first impact

mirror point to get the next point
get next intersection point, then repeat

*/

struct point {
    double x, y;

    point operator-(point p) { return { this->x - p.x, this->y - p.y }; }
    point operator+(point v) { return { this->x + v.x, this->y + v.y }; }
    point operator*(double d) { return { this->x * d, this->y * d }; }
};

bool is_on_ellipse(point p)
{
    return std::abs(4 * p.x * p.x + p.y * p.y) <= 100.00001; // wonky shit
}

bool is_exiting(point& p)
{
    return std::abs(p.x) <= 0.01 && p.y > 0;
}

double get_slope(point& p)
{
    return -4 * p.x / p.y;
}

double dot(point& v1, point& v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

point get_normal(point& p)
{
    point n = { 4 * p.x, p.y };
    double length = std::sqrt(n.x * n.x + n.y * n.y);

    return { n.x / length, n.y / length };
}

point reflect(point& v, point& n)
{
    double d = dot(v, n);
    d *= (d < 0) ? 1 : -1;

    return v - (n * (2 * dot(v, n)));
}

point get_intersection(point& p, point& v)
{
    // mitternachtsformel => ax^2 + bx + c = 0
    // 0 immer eine lösung, macht mitternachtsformel \infty einfacher :,)
    double a = 4 * v.x * v.x + v.y * v.y;
    double b = 8 * p.x * v.x + 2 * p.y * v.y;

    return p + (v * (-b / a));
}

unsigned long solution()
{
    unsigned long solution = 0;

    point p1 = { 0.0, 10.1 };
    point p2 = { 1.4, -9.6 };

    point v = p2 - p1;

    while ( !is_exiting(p2) )
    {
        point n = get_normal(p2);

        v = reflect(v, n);

        p1 = p2;
        p2 = get_intersection(p2, v);

        solution++;
    }

    return solution;
}

int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    unsigned long sol = solution();

    double runtime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin).count();

    print(runtime, sol);
    return 0;
}
