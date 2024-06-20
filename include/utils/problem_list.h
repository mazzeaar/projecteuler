#ifndef PROBLEM_LIST_H
#define PROBLEM_LIST_H

#include <vector>
#include <functional>
#include <map>
#include <iomanip>

struct ProblemList {
    using ProblemFunction = std::function<i64()>;

    static std::map<int, ProblemFunction>& getProblems()
    {
        static std::map<int, ProblemFunction> problems;
        return problems;
    }

    static void addProblem(int number, const ProblemFunction& problem)
    {
        getProblems()[number] = problem;
    }

    static std::string format_problem(int n)
    {
        std::string output = "Problem ";
        if ( n < 10 ) {
            output += "00";
        }
        else if ( n < 100 ) {
            output += "0";
        }
        output += std::to_string(n);

        return output;
    }

    static void print_problem(int n)
    {
        auto& problems = getProblems();
        auto it = problems.begin();
        if ( (it = problems.find(n)) == problems.end() ) {
            std::cout << "Problem " << n << " not found!\n";
            return;
        }

        ProblemList::ProblemFunction func = it->second;

        const std::string problem_text = format_problem(n) + ": ";
        std::cout << std::left << std::setw(20) << problem_text;

        auto begin = std::chrono::high_resolution_clock::now();
        const auto result = func();
        const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - begin).count();

        const std::string duration_text = "(" + std::to_string((double) duration / 1000000.) + " ms)";

        std::cout << std::right << std::setw(20) << result
            << std::right << std::setw(20) << duration_text
            << '\n';
    }
};

#define REGISTER_PROBLEM(PROBLEM_FUNC, PROBLEM_NUM) \
    namespace { \
        const bool registered_##PROBLEM_FUNC = []() { \
            ProblemList::addProblem(PROBLEM_NUM, PROBLEM_FUNC); \
            return true; \
        }(); \
    }

#endif // PROBLEM_LIST_H
