#include "euler_utils.h"
#include <fstream>

i64 solve_problem_42()
{
    std::fstream file("../inputs/0042_words.txt");
    std::string word = "";
    i64 result = 0;
    while ( std::getline(file, word, ',') ) {
        i64 tn = std::accumulate(word.begin() + 1, word.end() - 1, i64(0), [ ] (i64 tn, char c)
        {
            return tn + c - 'A' + 1;
        });

        // idk how reliable this is but its enough
        if ( float n = std::sqrtf(1 + 8 * tn); n == (int) n ) {
            ++result;
        }
    }

    ASSERT_EQUAL(result, 162);
    return result;
}

REGISTER_PROBLEM(solve_problem_42, 42)