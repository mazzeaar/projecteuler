#include <algorithm>
#include <limits>
#include <ranges>

#include "euler_utils.h"

namespace sr = std::ranges;
namespace sv = std::ranges::views;

static constexpr i64 N          = 100;
static constexpr i64 max_digits = 200;

auto naive_solution() {
    auto rng = sv::iota(i64{0}, N);

    std::vector<std::vector<std::array<uint8_t, max_digits>>> results;
    results.reserve(100);

    for (auto a : rng) {
        results.emplace_back();
        auto& cur = results.back();
        cur.reserve(100);
        cur.emplace_back();
        cur.back().front() = 1;

        for (auto _ : rng) {
            auto const& old = cur.back();
            cur.emplace_back();

            i64 carry = 0;
            for (auto [prev, now] : std::views::zip(old, cur.back())) {
                carry += prev * a;
                now = carry % 10;
                carry /= 10;
            }
        }
    }

    return results;
}

i64 solve_problem_56() {
    auto arr = naive_solution();

    auto best_a = 0;
    auto best_b = 0;

    i64 result = std::numeric_limits<i64>::min();
    for (auto a : sv::iota(0, N)) {
        for (auto b : sv::iota(0, N)) {
            auto const& num = arr[a][b];

            auto tmp = sr::fold_left(num, i64{}, std::plus{});
            if (tmp > result) {
                best_a = a;
                best_b = b;
            }
            result = sr::max(result, tmp);
        }
    }

    // std::println("best digital sum is for {}^{} with {}", best_a, best_b, result);

    return result;
}

REGISTER_PROBLEM(solve_problem_56, 56)
