#include "euler_utils.h"

i64 solve_problem_40()
{
    static std::array<int, 7> pow10 = {
        1, 10, 100, 1000, 10000,
        100000, 1000000
    };

    i64 result = std::accumulate(pow10.begin(), pow10.end(), i64(1), [ ] (i64 acc, i64 position)
    {
        i64 range_end;
        i64 digit_len = 0;
        for ( i64 s = 0; s < position; ++digit_len ) {
            range_end = s;
            s += 9 * pow10[digit_len] * (digit_len + 1);
        }

        const i64 range_offset = (position - range_end - 1);
        const i64 num_at_pos = pow10[digit_len - 1] + (range_offset / digit_len);
        return (std::to_string(num_at_pos)[range_offset % digit_len] - '0') * acc;
    });

    ASSERT_EQUAL(result, 210);
    return result;
}

REGISTER_PROBLEM(solve_problem_40, 40)
