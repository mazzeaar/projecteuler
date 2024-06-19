#include "euler_utils.h"
#include <fstream>

std::vector<std::string> read_input()
{
    const std::string path = "../inputs/0022_names.txt";
    std::ifstream file(path);
    if ( !file.is_open() ) {
        std::cerr << "Failed to open the file." << std::endl;
        return {};
    }

    std::string line;
    std::vector<std::string> names;

    if ( std::getline(file, line) ) {
        std::stringstream ss(line);
        std::string name;

        while ( std::getline(ss, name, ',') ) {
            name.erase(remove(name.begin(), name.end(), '"'), name.end());

            for ( char& c : name ) {
                if ( c >= 'A' ) {
                    c = ('a' + (c - 'A'));
                }
            }

            names.push_back(name);
        }
    }

    file.close();

    std::sort(names.begin(), names.end());
    return names;
}

size_t solve_problem_22()
{
    std::vector<std::string> names;
    try {
        names = read_input();
    }
    catch ( std::exception& e ) {
        std::cout << e.what() << '\n';
        return 0;
    }

    const size_t size = names.size();
    size_t result = 0;
    for ( size_t i = 0; i < size; ++i ) {
        size_t score = 0;
        for ( char c : names[i] ) {
            score += (size_t) (c - 'a' + 1);
        }
        result += score * (i+1);
    }

    ASSERT_EQUAL(result, 871198282);
    return result;
}

REGISTER_PROBLEM(solve_problem_22, 22)
