#include <iostream>
#include <chrono>
#include <iomanip>
#include <string>
#include <cassert>

/*
 * --------------------------------
 * Problem: '17'
 * https://projecteuler.net/problem=17
 * --------------------------------
 * @amazzetta
 *
 * Really annoying problem to solve, its not clean and its not efficient, but it works.
 *
 * ################################
 * #  Problem 17
 * #  Solved in : 26 µs(0 ms)
 * #  Solution : 21124
 * ################################
 */

void print(double runtime, long int solution = 0)
{
    if ( solution == 0 ) {
        std::cout << "\nSolution to problem 17 is not implemented yet!\n\n";
        return;
    }

    std::cout << "\n################################\n"
        << "#  Problem 17\n"
        << "#  Solved in: " << std::fixed << std::setprecision(0) << runtime << " µs (" << runtime / 1000 << " ms)\n"
        << "#  Solution: " << solution << "\n"
        << "################################\n";
}

// --------------------------------

int get_decimal(int n)
{
    assert(n >= 0 && n < 10 && "n is not in range [0,9]");

    switch ( n ) {
        case 0: return 0; // zero (not counted in the problem)
        case 1: return 3; // one
        case 2: return 3; // two
        case 3: return 5; // three
        case 4: return 4; // four
        case 5: return 4; // five
        case 6: return 3; // six
        case 7: return 5; // seven
        case 8: return 5; // eight
        case 9: return 4; // nine
        default: return 0;
    }
}

int get_teens(int n)
{
    assert(n >= 10 && n < 20 && "n is not a teen number");

    switch ( n ) {
        case 10: return 3; // ten
        case 11: return 6; // eleven
        case 12: return 6; // twelve
        case 13: return 8; // thirteen
        case 14: return 8; // fourteen
        case 15: return 7; // fifteen
        case 16: return 7; // sixteen
        case 17: return 9; // seventeen
        case 18: return 8; // eighteen
        case 19: return 8; // nineteen
        default: return 0;
    }
}

int get_decas(int n)
{
    assert(n >= 20 && n <= 90 && n % 10 == 0 && "n is not decal and in range [20,90]");

    switch ( n ) {
        case 20: return 6; // twenty
        case 30: return 6; // thirty
        case 40: return 5; // forty
        case 50: return 5; // fifty
        case 60: return 5; // sixty
        case 70: return 7; // seventy
        case 80: return 6; // eighty
        case 90: return 6; // ninety
        default: return 0;
    }
}

// --------------------------------

unsigned long long get_char_count(int n)
{
    unsigned long long value = 0;
    if ( n == 1000 ) {
        return 11; // "one thousand"
    }

    if ( n >= 100 ) {
        value += get_decimal(n / 100) + 7; // "hundred"
        if ( n % 100 != 0 ) {
            value += 3; // "and"
        }
        n %= 100;
    }

    if ( n >= 20 ) {
        value += get_decas((n / 10) * 10);
        if ( n % 10 != 0 ) {
            value += get_decimal(n % 10);
        }
    }
    else if ( n >= 10 && n < 20 ) {
        value += get_teens(n);
    }
    else {
        value += get_decimal(n);
    }

    return value;
}

unsigned long solution()
{
    unsigned long solution = 0;

    for ( int i = 1; i <= 1000; ++i ) {
        solution += get_char_count(i);
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
