// --------------------------------
// default includes

#include <iostream>
#include <chrono>
#include <iomanip>

/*
 * --------------------------------
 * Problem: '39'
 * https://projecteuler.net/problem=39
 * --------------------------------
 * @amazzetta
 *
 * Disgusting brute force solution, but hey ¯\_(ツ)_/¯
 *
 * ################################
 * #     Problem 39
 * #     Solved in: 53770215.0000 µs
 * #     Solution: 840
 * ################################
 */

void print(double runtime, long int solution = 0)
{
    if ( solution == 0 )
    {
        std::cout << "\nSolution to problem 39 is not implemented yet!\n" << std::endl;
        return;
    }

    std::cout << "################################" << std::endl;
    std::cout << "#     Problem 39" << std::endl;
    std::cout << "#     Solved in: " << std::fixed << std::setprecision(4) << runtime << " µs" << std::endl;
    std::cout << "#     Solution: " << solution << std::endl;
    std::cout << "################################\n" << std::endl;
}

// --------------------------------

struct Triangle {
    int a;
    int b;
    int c;
};

bool is_integer_right_triangle(Triangle t)
{
    return (t.a * t.a + t.b * t.b) == (t.c * t.c);
}

int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    unsigned long solution = 0;
    int PERIMETER = 1000;
    std::pair<int, int> max_solutions = { 0, 0 };

    for ( int perimeter = 1; perimeter <= PERIMETER; ++perimeter )
    {
        int temp_solution = 0;

        for ( int a = 0; a <= perimeter; ++a )
        {
            for ( int b = a + 1; b <= perimeter; ++b )
            {
                for ( int c = b + 1; c <= perimeter; ++c )
                {
                    if ( a + b + c == perimeter && is_integer_right_triangle({ a, b, c }) )
                    {
                        //std::cout << "a: " << a << " b: " << b << " c: " << c << "\n";
                        temp_solution++;
                    }
                }
            }
        }

        if ( temp_solution > max_solutions.second )
        {
            max_solutions.first = perimeter;
            max_solutions.second = temp_solution;
        }
    }

    solution = max_solutions.first;

    double runtime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin).count();
    print(runtime, solution);

    // print the solutions for the best perimeter
    for ( int a = 0; a <= max_solutions.first; ++a )
    {
        for ( int b = a + 1; b <= max_solutions.first; ++b )
        {
            for ( int c = b + 1; c <= max_solutions.first; ++c )
            {
                if ( a + b + c == max_solutions.first && is_integer_right_triangle({ a, b, c }) )
                {
                    std::cout << "a: " << a << " b: " << b << " c: " << c << "\n";
                }
            }
        }
    }

    return 0;
}
