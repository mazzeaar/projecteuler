#include "utils/factorial.h"

size_t runtime_small_factorial(int n)
{
    assert(0 <= n && n <= 20 && "small_fib is only accurate up to 20!");

    switch ( n ) {
        case 0: return small_factorial<0>::value;
        case 1: return small_factorial<1>::value;
        case 2: return small_factorial<2>::value;
        case 3: return small_factorial<3>::value;
        case 4: return small_factorial<4>::value;
        case 5: return small_factorial<5>::value;
        case 6: return small_factorial<6>::value;
        case 7: return small_factorial<7>::value;
        case 8: return small_factorial<8>::value;
        case 9: return small_factorial<9>::value;
        case 10: return small_factorial<10>::value;
        case 11: return small_factorial<11>::value;
        case 12: return small_factorial<12>::value;
        case 13: return small_factorial<13>::value;
        case 14: return small_factorial<14>::value;
        case 15: return small_factorial<15>::value;
        case 16: return small_factorial<16>::value;
        case 17: return small_factorial<17>::value;
        case 18: return small_factorial<18>::value;
        case 19: return small_factorial<19>::value;
        case 20: return small_factorial<20>::value;
        default: return 0;
    }
}