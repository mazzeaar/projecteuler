#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
#include <fstream>

/*
 * --------------------------------
 * Problem: '18'
 * https://projecteuler.net/problem=18
 * --------------------------------
 * @amazzetta
 *
 * ################################
 * #  Problem 18
 * #  Solved in: 69 µs (0 ms)
 * #  Solution: 1074
 * ################################
 */

void print(double runtime, long int solution = 0)
{
    if ( solution == 0 ) {
        std::cout << "\nSolution to problem 18 is not implemented yet!\n\n";
        return;
    }

    std::cout << "\n################################\n"
        << "#  Problem 18\n"
        << "#  Solved in: " << std::fixed << std::setprecision(0) << runtime << " µs (" << runtime / 1000 << " ms)\n"
        << "#  Solution: " << solution << "\n"
        << "################################\n";
}

// --------------------------------

std::vector<std::vector<int>> read_triangle(const std::string& path)
{
    std::fstream file(path);
    std::string line = "";

    std::vector<std::vector<int>> triangle(15, std::vector<int>(15, 0));

    int row = 0, col = 0;
    while ( file >> line ) {
        const int num = std::stoi(line);
        triangle[row][col] = num;
        ++col;
        if ( col > row ) {
            col = 0;
            ++row;
        }
    }

    return triangle;
}

void print_triangle(const std::vector<std::vector<int>>& triangle)
{
    for ( auto v : triangle ) {
        for ( auto i : v ) {
            std::cout << std::left << std::setw(4) << i << ' ';
        }
        std::cout << std::endl;
    }
}

unsigned long solution()
{
    unsigned long solution = 0;
    const std::string path = "input/0018_triangle.txt";
    auto triangle = read_triangle(path);

    const int n = triangle.size();

    for ( int row = n-2; row >= 0; --row ) {
        for ( int col = 0; col <= row; ++col ) {
            triangle[row][col] += std::max(triangle[row+1][col], triangle[row+1][col+1]);
        }
    }

    return triangle[0][0];
}

int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    unsigned long sol = solution();

    double runtime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin).count();

    print(runtime, sol);
    return 0;
}
