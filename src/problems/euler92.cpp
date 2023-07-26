#include <iostream>
#include <chrono>
#include <iomanip>

/*
 * --------------------------------
 * Problem: '92'
 * https://projecteuler.net/problem=92
 * --------------------------------
 * @amazzetta
 */

void print(double runtime, long int solution = 0)
{
    if ( solution == 0 )
    {
        std::cout << "\nSolution to problem 92 is not implemented yet!\n\n";
        return;
    }

    std::cout << "\n################################\n"
        << "#  Problem 92\n"
        << "#  Solved in: " << std::fixed << std::setprecision(0) << runtime << " µs (" << runtime / 1000 << " ms)\n"
        << "#  Solution: " << solution << "\n"
        << "################################\n";
}

// --------------------------------

int get_next(int n)
{
    int next = 0;
    int tmp;

    while ( n != 0 )
    {
        tmp = (n % 10);
        n /= 10;
        next += tmp * tmp;
    }
    return next;
}

unsigned long solution()
{
    unsigned long solution = 0;
    int n = 10;
    for ( int i = 0;i < 10;++i )
    {
        std::cout << n;
        n = get_next(n);
        std::cout << " -> " << n;
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