#include <iostream>
#include <string>
#include <iomanip>

#include "euler_utils.h"

int main(int argc, char* argv[])
{
    auto& problems = ProblemList::getProblems();
    if ( argc > 1 ) {
        int problem_number = std::stoi(argv[1]);
        auto it = problems.find(problem_number);
        if ( it != problems.end() ) {
            it->second();
        }
        else {
            std::cout << ProblemList::format_problem(problem_number) << " not found!" << std::endl;
        }
    }
    else {
        std::cout << "Running all problems sequentially:\n";
        for ( const auto& [number, problem] : problems ) {
            ProblemList::print_problem(number, problem);
        }
    }

    return 0;
}
