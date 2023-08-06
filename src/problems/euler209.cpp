#include <iostream>
#include <chrono>
#include <iomanip>

/*
 * --------------------------------
 * Problem: '209'
 * https://projecteuler.net/problem=209
 * --------------------------------
 * @amazzetta
 */

void print(double runtime, long int solution = 0)
{
    if ( solution == 0 )
    {
        std::cout << "\nSolution to problem 209 is not implemented yet!\n\n";
        return;
    }

    std::cout << "\n################################\n"
        << "#  Problem 209\n"
        << "#  Solved in: " << std::fixed << std::setprecision(0) << runtime << " µs (" << runtime / 1000 << " ms)\n"
        << "#  Solution: " << solution << "\n"
        << "################################\n";
}

// --------------------------------

bool formula(const std::vector<bool>& tau, bool a, bool b, bool c, bool d, bool e, bool f)
{
    // not sure about this one
    int idx1 = a * 32 + b * 16 + c * 8 + d * 4 + e * 2 + f;
    int idx2 = b * 32 + c * 16 + d * 8 + e * 4 + f * 2 + (a ^ (b & c));
    std::cout << idx1 << " " << idx2 << std::endl;
    return tau[idx1] & tau[idx2];
}

bool is_valid(const std::vector<bool>& tau)
{
    // ugly but idc
    for ( int a = 0; a <= 1; ++a )
        for ( int b = 0; b <= 1; ++b )
            for ( int c = 0; c <= 1; ++c )
                for ( int d = 0; d <= 1; ++d )
                    for ( int e = 0; e <= 1; ++e )
                        for ( int f = 0; f <= 1; ++f )
                            if ( formula(tau, a, b, c, d, e, f) )
                            {
                                return false; // formula is true => tau is invalid
                            }
    return true; // formula is false => tau is valid
}

unsigned long solution()
{
    unsigned long solution = 0;

    for ( )
    {
        /*
        problem: truth table with 6 variables has 2^6 = 64 rows, this results in 2^64 possible truth tables...
        => i think the mapping from t1 to t2 is bijective so there are less tables
        => meaning we can just find cycles and check one table per cycle => all other tables have the same truth value
        */
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
