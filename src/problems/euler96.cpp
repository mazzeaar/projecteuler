// --------------------------------
// default includes

#include <iostream>
#include <chrono>
#include <iomanip>

/*
 * --------------------------------
 * Problem: '96'
 * https://projecteuler.net/problem=96
 * --------------------------------
 * @amazzetta
 *
 * ################################
 * #  Problem 96
 * #  Solved in: 327099 µs (327 ms)
 * #  Solution: 24702
 * ################################
 */

void print(double runtime, long int solution = 0)
{
    if ( solution == 0 )
    {
        std::cout << "\nSolution to problem 96 is not implemented yet!\n" << std::endl;
        return;
    }

    std::cout << "\n################################\n"
        << "#  Problem 96\n"
        << "#  Solved in: " << std::fixed << std::setprecision(0) << runtime << " µs (" << runtime / 1000 << " ms)\n"
        << "#  Solution: " << solution << "\n"
        << "################################\n";
}

// --------------------------------

#include <vector>
#include <fstream>
#include <string>

using sudoku = std::vector<int>;

std::vector<sudoku> read_sudokus(std::string& path)
{
    std::vector<sudoku> sudokus;
    std::ifstream file(path);

    std::string line;
    while ( std::getline(file, line) )
    {
        if ( line[0] == 'G' )
        {
            sudoku puzzle;
            for ( int i = 0; i < 9; ++i )
            {
                std::getline(file, line);
                for ( int j = 0; j < line.size(); ++j )
                {
                    puzzle.push_back(line[j] - '0');
                }
            }
            sudokus.push_back(puzzle);
        }
    }

    return sudokus;
}

void print_one(sudoku& s)
{
    std::cout << "\n";
    for ( int i = 0; i < 9; ++i )
    {
        std::cout << (i % 3 == 0 ? " =========================================\n"
            : " -----------------------------------------\n");
        for ( int j = 0; j < 9; ++j )
        {
            std::cout << (j % 3 == 0 ? " || " : " | ") << s[i * 9 + j];
        }
        std::cout << " ||\n";
    }
    std::cout << " =========================================\n";
}

void print_all(std::vector<sudoku>& sudokus)
{
    for ( int i = 0; i < sudokus.size();++i )
    {
        std::cout << "\nSUDOKU " << i << ":\n";
        print_one(sudokus[i]);
    }
}

// returns a vector of all possible values for a given cell
std::vector<int> possible_values(sudoku& grid, int pos)
{
    std::vector<int> possible(9, true);
    int row = pos / 9;
    int col = pos % 9;

    // check row and column
    for ( int i = 0; i < 9; i++ )
    {
        if ( grid[row * 9 + i] != 0 )
        {
            possible[grid[row * 9 + i] - 1] = false;
        }
        if ( grid[i * 9 + col] != 0 )
        {
            possible[grid[i * 9 + col] - 1] = false;
        }
    }

    int grid_row = row - row % 3;
    int grid_col = col - col % 3;

    // check 3x3 grid
    for ( int i = 0; i < 3; i++ )
    {
        for ( int j = 0; j < 3; j++ )
        {
            if ( grid[(grid_row + i) * 9 + grid_col + j] > 0 )
            {
                possible[grid[(grid_row + i) * 9 + grid_col + j] - 1] = false;
            }
        }
    }

    std::vector<int> values;
    for ( int i = 0; i < 9; i++ )
    {
        if ( possible[i] )
        {
            values.push_back(i + 1);
        }
    }

    return values;
}

bool solve(sudoku& grid)
{
    int min_pos = -1;
    std::vector<int> min_values;

    // find the cell with the least possible values to try
    for ( int pos = 0; pos < 81; ++pos )
    {
        if ( grid[pos] == 0 )
        {
            auto values = possible_values(grid, pos);
            if ( min_pos == -1 || values.size() < min_values.size() )
            {
                min_pos = pos;
                min_values = std::move(values);
            }
        }

    }

    // all cells are filled -> solution found
    if ( min_pos == -1 ) return true;

    // try all possible values for the cell with the least possible values
    for ( int value : min_values )
    {
        grid[min_pos] = value;

        if ( solve(grid) )
        {
            return true;
        }

        grid[min_pos] = 0;
    }

    return false;
}


int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    unsigned long solution = 0;
    std::string path = "input/0096_sudoku.txt";
    std::vector<sudoku> sudokus = read_sudokus(path);

    int counter = 1;
    for ( sudoku& s : sudokus )
    {
        std::chrono::steady_clock::time_point solve_begin = std::chrono::steady_clock::now();
        solve(s);
        double solve_runtime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - solve_begin).count();
        std::cout << "solved " << counter++ << " in " << solve_runtime << " µs\n";
        solution += s[0] * 100 + s[1] * 10 + s[2];
    }

    double runtime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin).count();
    print(runtime, solution);

    return 0;
}
