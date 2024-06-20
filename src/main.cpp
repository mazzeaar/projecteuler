#include <iostream>
#include <string>
#include <iomanip>
#include <cctype> // for isdigit

#include "euler_utils.h"

using Problems = std::map<int, ProblemList::ProblemFunction>;

void run_last_problem(Problems& problems);
void run_all_problems(Problems& problems);
void run_specific_problem(Problems& problems, int n);
bool is_number(const std::string& s);

int main(int argc, char* argv[])
{
    auto& problems = ProblemList::getProblems();

    if ( argc == 1 ) {
        run_last_problem(problems);
        return 0;
    }

    std::string arg = argv[1];
    if ( arg == "all" ) {
        run_all_problems(problems);
    }
    else if ( is_number(arg) ) {
        const int n = std::stoi(arg);
        run_specific_problem(problems, n);
    }
    else {
        std::cout << "Usage:\n"
            << "    ./main \'all\' - to run all problems\n"
            << "    ./main <N> - to run problem N\n";
    }

    return 0;
}

void run_last_problem(Problems& problems)
{
    std::cout << "Running last solved Problem:\n";
    int max = 0;
    for ( auto it = problems.begin(); it != problems.end(); ++it ) {
        max = std::max(max, it->first);
    }

    ProblemList::print_problem(max);
}

void run_all_problems(Problems& problems)
{
    std::cout << "Running all problems sequentially:\n";
    for ( const auto& [number, _] : problems ) {
        ProblemList::print_problem(number);
    }
}

void run_specific_problem(Problems& problems, int n)
{
    std::cout << "Running problem " << n << ":\n";
    ProblemList::print_problem(n);
}

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), s.end(),
        [ ] (unsigned char c) { return !std::isdigit(c); }) == s.end();
}