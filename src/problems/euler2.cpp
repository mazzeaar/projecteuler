#include <iostream>
#include <chrono>
#include <iomanip>

/*
 * --------------------------------
 * Problem: '2'
 * https://projecteuler.net/problem=2
 * --------------------------------
 * @amazzetta
 *
 * ################################
 * #  Problem 2
 * #  Solved in: 1 µs (0 ms)
 * #  Solution: 4613732
 * ################################
 */

void print(double runtime, long int solution = 0)
{
    if ( solution == 0 )
    {
        std::cout << "\nSolution to problem 2 is not implemented yet!\n\n";
        return;
    }

    std::cout << "\n################################\n"
        << "#  Problem 2\n"
        << "#  Solved in: " << std::fixed << std::setprecision(0) << runtime << " µs (" << runtime / 1000 << " ms)\n"
        << "#  Solution: " << solution << "\n"
        << "################################\n";
}

// --------------------------------

std::vector<int> fibonacci(int limit)
{
    std::vector<int> fib;
    fib.push_back(1);
    fib.push_back(2);

    int i = 2;
    while ( fib[i - 1] + fib[i - 2] < limit )
    {
        fib.push_back(fib[i - 1] + fib[i - 2]);
        i++;
    }

    return fib;
}

unsigned long solution()
{
    unsigned long solution = 0;

    std::vector<int> fib = fibonacci(4000000);

    for ( auto& n : fib )
    {
        if ( n % 2 == 0 )
            solution += n;
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
