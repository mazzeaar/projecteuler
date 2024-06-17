#include <iostream>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include <vector>

/*
 * --------------------------------
 * Problem: '92'
 * https://projecteuler.net/problem=92
 * --------------------------------
 * @amazzetta
 *
 * ################################
 * #  Problem 92
 * #  Solved in: 506118 µs (506 ms)
 * #  Solution: 8581146
 * ################################
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
        next += (tmp * tmp);
    }

    return next;
}

unsigned long solution()
{
    unsigned long count = 0;
    int range = static_cast<int>(1e7);

    std::vector<bool> cycle(range, false); // no number exceeds the range, max = 7 * 9^2

    for ( int i = 1; i < range; ++i )
    {
        int num = i;
        std::vector<int> chain;

        while ( std::find(chain.begin(), chain.end(), num) == chain.end() )
        {
            chain.push_back(num);
            num = get_next(num);

            if ( num == 1 )
            {
                break;
            }
            else if ( cycle[num] || num == 89 )
            {
                for ( int& n : chain )
                {
                    cycle[n] = true;
                }
                ++count;
                break;
            }
        }
    }

    return count;
}

int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    unsigned long sol = solution();

    double runtime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin).count();

    print(runtime, sol);

    return 0;
}