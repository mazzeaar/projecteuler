#include <iostream>
#include <chrono>
#include <iomanip>

/*
 * --------------------------------
 * Problem: '{NUMBER}'
 * https://projecteuler.net/problem={NUMBER}
 * --------------------------------
 * @amazzetta
 */

void print(double runtime, long int solution = 0)
{
    if ( solution == 0 )
    {
        std::cout << "\nSolution to problem {NUMBER} is not implemented yet!\n\n";
        return;
    }

    std::cout << "\n################################\n"
        << "#  Problem {NUMBER}\n"
        << "#  Solved in: " << std::fixed << std::setprecision(0) << runtime << " µs (" << runtime / 1000 << " ms)\n"
        << "#  Solution: " << solution << "\n"
        << "################################\n";
}

// --------------------------------

unsigned long solution()
{
    unsigned long solution = 0;

    // TODO: Implement solution here

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