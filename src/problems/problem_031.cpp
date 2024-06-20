#include "euler_utils.h"
#include <vector>

int iterative(int val, int coin_idx, const std::vector<int>& coins, std::vector<std::vector<int>>& memo)
{
    if ( val == 0 ) return 1;
    if ( val < 0 || coin_idx < 0 ) return 0;

    if ( memo[val][coin_idx] != -1 ) {
        return memo[val][coin_idx];
    }

    int include_coin = iterative(val - coins[coin_idx], coin_idx, coins, memo);
    int exclude_coin = iterative(val, coin_idx - 1, coins, memo);

    memo[val][coin_idx] = include_coin + exclude_coin;
    return memo[val][coin_idx];
}

i64 solve_problem_31()
{
    const std::vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 200 };
    std::vector<std::vector<int>> memo(201, std::vector<int>(coins.size(), -1));
    i64 result = iterative(200, coins.size() - 1, coins, memo);

    ASSERT_EQUAL(result, 73682);
    return result;
}

REGISTER_PROBLEM(solve_problem_31, 31)
