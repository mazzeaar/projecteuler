// --------------------------------
// default includes

#include <iostream>
#include <chrono>
#include <iomanip>

/*
 * --------------------------------
 * Problem: '42'
 * https://projecteuler.net/problem=42
 * --------------------------------
 * @amazzetta
 *
 * ################################
 * #     Problem 42
 * #     Solved in: 878.0000 µs
 * #     Solution: 162
 * ################################
 */

#include <fstream>
#include <string>

void print(double runtime, long int solution = 0)
{
    if ( solution == 0 )
    {
        std::cout << "\nSolution to problem 42 is not implemented yet!\n" << std::endl;
        return;
    }

    std::cout << "################################" << std::endl;
    std::cout << "#     Problem 42" << std::endl;
    std::cout << "#     Solved in: " << std::fixed << std::setprecision(4) << runtime << " µs" << std::endl;
    std::cout << "#     Solution: " << solution << std::endl;
    std::cout << "################################\n" << std::endl;
}

// --------------------------------

int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    int solution = 0;

    std::ifstream file("input/0042_words.txt");

    const std::string delimeter = ",";

    std::string line;
    std::string word;
    while ( std::getline(file, line, delimeter[0]) )
    {
        int word_sum = 0;

        for ( int i = 1; i < line.size() - 1; ++i )
        {
            word_sum += line[i] - 'A' + 1;
        }

        float index2 = sqrtf(1 + 2 * word_sum * 4) - 1 / 2;

        if ( index2 - (int) index2 <= 0.0001 )
        {
            ++solution;
        }
    }

    double runtime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin).count();
    print(runtime, solution);

    return 0;
}
