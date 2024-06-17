// --------------------------------
// default includes

#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>

/*
 * --------------------------------
 * Problem: '61'
 * https://projecteuler.net/problem=61
 * --------------------------------
 * @amazzetta
 *
 * ################################
 * #  Problem 61
 * #  Solved in: 5218 µs (5 ms)
 * #  Solution: 28684
 * ################################
 */

void print(double runtime, long int solution = 0)
{
    if ( solution == 0 )
    {
        std::cout << "\nSolution to problem 61 is not implemented yet!\n\n";
        return;
    }

    std::cout << "\n################################\n"
        << "#  Problem 61\n"
        << "#  Solved in: " << std::fixed << std::setprecision(0) << runtime << " µs (" << runtime / 1000 << " ms)\n"
        << "#  Solution: " << solution << "\n"
        << "################################\n";
}

// --------------------------------

struct PolyNum {
    int value;
    int firstTwo;
    int lastTwo;
};

long long comparisons = 0;

std::vector<PolyNum> genNumbers(int factor)
{
    std::vector<PolyNum> numbers;
    for ( int n = 1;; ++n )
    {
        int value = n * ((factor - 2) * n - (factor - 4)) / 2;
        if ( value > 9999 ) break;
        if ( value > 999 )
        {
            numbers.push_back({ value, value / 100, value % 100 });
        }
    }
    return numbers;
}

bool findCycle(std::vector<PolyNum> numbers[6], std::array<int, 6>& sequence, std::array<bool, 6>& used, int depth = 0)
{
    // check if cycle
    if ( depth == 6 )
        return sequence[0] / 100 == sequence[5] % 100;

    // try all unused numbers from all types
    for ( int i = 0; i < 6; ++i )
    {
        if ( used[i] ) continue;

        for ( auto& number : numbers[i] )
        {
            comparisons++;

            if ( depth != 0 && number.firstTwo != sequence[depth - 1] % 100 )
                continue;

            sequence[depth] = number.value;
            used[i] = true;

            if ( findCycle(numbers, sequence, used, depth + 1) )
                return true;

            used[i] = false;
        }
    }
    return false;
}

int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    unsigned long solution = 0;

    std::vector<PolyNum> numbers[6];
    for ( int i = 0; i < 6; ++i )
        numbers[i] = genNumbers(i + 3);

    std::array<int, 6> sequence;
    std::array<bool, 6> used = { false, false, false, false, false, false };

    if ( !findCycle(numbers, sequence, used) ) return 1;

    for ( int num : sequence )
        solution += num;

    double runtime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin).count();
    print(runtime, solution);

    return 0;
}
