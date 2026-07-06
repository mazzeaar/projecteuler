#include <algorithm>
#include <queue>
#include <ranges>

#include "euler_utils.h"
#include "utils/math.h"

i64 solve_problem_55() {
    static constexpr i64 N        = 10000;
    static constexpr int max_iter = 50;

    auto is_lychrel = [](i64 x) {
        return std::ranges::none_of(std::views::iota(0, max_iter), [&x](auto&& /*step*/) {
            x += math::get_reverse(x);
            return math::is_palindrome(x);
        });
    };

    return std::ranges::count_if(std::views::iota(1, N), is_lychrel);
}

REGISTER_PROBLEM(solve_problem_55, 55)
