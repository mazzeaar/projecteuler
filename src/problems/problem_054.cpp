#include "euler_utils.h"
#include <fstream>
#include <algorithm>

struct Hand {
    using score_t = uint32_t;

    std::array<int, 13> rank;
    std::array<int, 4> suit;

    score_t score = 0;
    int n_cards = 0;

    Hand() : rank({}), suit({}) { }

    void add(const std::string& card)
    {
        ++n_cards;

        char c_rank = card[0];
        if ( c_rank >= '2' && c_rank <= '9' ) {
            ++rank[c_rank - '2'];
        }
        else {
            switch ( c_rank ) {
                case 'T': ++rank[8]; break;
                case 'J': ++rank[9]; break;
                case 'Q': ++rank[10]; break;
                case 'K': ++rank[11]; break;
                case 'A': ++rank[12]; break;
                default: break;
            }
        }

        switch ( card[1] ) {
            case 'C': ++suit[0]; break;
            case 'H': ++suit[1]; break;
            case 'D': ++suit[2]; break;
            case 'S': ++suit[3]; break;
            default: break;
        }

        if ( n_cards == 5 ) {
            eval();
        }
    }

    bool operator>(const Hand& other) const { return score > other.score; }

private:
    /**
     * evaluates the trivial hands
     *  - pair, three, four, highest card
     */
    template <int N>
    inline score_t tuple_score()
    {
        score_t score = 0;
        for ( int i = rank.size() - 1; i >= 0; --i ) {
            if ( rank[i] == N ) {
                score |= (0b1 << i);
                rank[i] = 0; // we set the counted cards to zero to avoid recounting them for N=1 (highest card)
            }
        }

        return score;
    }

    inline score_t straight_score()
    {
        score_t score = 0;

        for ( int i = rank.size() - 1; i >= 4; --i ) {
            if ( rank[i] && rank[i-1] && rank[i-2] && rank[i-3] && rank[i-4] ) {
                score = 0b1 << i;
                return score;
            }
        }

        // special case for A,2,3,4,5
        if ( rank[12] && rank[0] && rank[1] && rank[2] && rank[3] ) {
            score = 0b1;
        }

        return score;
    }

    inline score_t shift_block(score_t bits) { return bits << 13; }

    inline score_t set_score(int score)
    {
        return score_t((score_t(16) - score) << (sizeof(score_t) * 8 - 5));
    }

    template<typename... Args>
    void generate_score(int hand_score, Args... args)
    {
        score = set_score(hand_score);
        score |= shift_and_combine(args...);
    }

    // base case
    score_t shift_and_combine() { return 0; }

    // merge the scores
    template<typename First, typename... Rest>
    score_t shift_and_combine(First first, Rest... rest)
    {
        return (first << (13 * sizeof...(rest))) | shift_and_combine(rest...);
    }

    void eval()
    {
        const bool is_flush = std::any_of(suit.begin(), suit.end(), [ ] (int i) { return i == 5; });

        const score_t straight_s = straight_score();
        const score_t pair_score = tuple_score<2>();
        const score_t three_score = tuple_score<3>();
        const score_t four_score = tuple_score<4>();
        const score_t highest_card = tuple_score<1>();

        if ( is_flush && rank[12] && straight_s ) {
            generate_score(1);
        }
        if ( is_flush && straight_s ) {
            generate_score(2, straight_s);
        }
        else if ( four_score ) {
            generate_score(3, four_score, highest_card);
        }
        else if ( pair_score && three_score ) {
            generate_score(4, three_score, pair_score);
        }
        else if ( is_flush ) {
            generate_score(5, highest_card);
        }
        else if ( straight_s ) {
            generate_score(6, straight_s);
        }
        else if ( three_score ) {
            generate_score(7, three_score, highest_card);
        }
        else if ( __builtin_popcountll(pair_score) == 2 ) {
            generate_score(8, pair_score, highest_card);
        }
        else if ( pair_score ) {
            generate_score(9, pair_score, highest_card);
        }
        else {
            generate_score(10, highest_card);
        }
    }
};

i64 solve_problem_54()
{
    i64 result = 0;

    const std::string path = "../inputs/0054_poker.txt";
    std::fstream file(path);
    std::string line;
    while ( std::getline(file, line) ) {
        std::istringstream ss(line);
        std::string card;

        Hand hand1;
        for ( int i = 0; i < 5; ++i ) {
            ss >> card;
            hand1.add(card);
        }

        Hand hand2;
        for ( int i = 0; i < 5; ++i ) {
            ss >> card;
            hand2.add(card);
        }

        result += (hand1 > hand2);
    }

    ASSERT_EQUAL(result, 376);
    return result;
}

REGISTER_PROBLEM(solve_problem_54, 54)
