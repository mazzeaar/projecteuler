// --------------------------------
// default includes

#include <iostream>
#include <chrono>
#include <iomanip>

// --------------------------------

/*
 * --------------------------------
 * Problem: '1'
 * https://projecteuler.net/problem=1
 * --------------------------------
 * @amazzetta
 *
 * ################################
 * #     Problem 1
 * #     Solved in: 3.0000 µs
 * #     Solution: 233168
 * ################################
 */

void print(double runtime, long int solution = 0)
{
    if ( solution == 0 )
    {
        std::cout << "\nSolution to problem 1 is not implemented yet!\n" << std::endl;
        return;
    }

    std::cout << "################################" << std::endl;
    std::cout << "#     Problem 1" << std::endl;
    std::cout << "#     Solved in: " << std::fixed << std::setprecision(4) << runtime << " µs" << std::endl;
    std::cout << "#     Solution: " << solution << std::endl;
    std::cout << "################################\n" << std::endl;
}

int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    unsigned long solution = 0;

    for ( unsigned int i = 0; i < 1000; i++ )
    {
        if ( i % 3 == 0 || i % 5 == 0 )
        {
            solution += i;
        }
    }

    double runtime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin).count();
    print(runtime, solution);

    return 0;
}
