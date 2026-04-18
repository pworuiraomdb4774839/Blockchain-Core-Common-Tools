#ifndef NUM_SAFE_CALC_HPP
#define NUM_SAFE_CALC_HPP

#include <cstdint>

class NumSafeCalc
{
public:
    static bool safe_add(uint64_t a, uint64_t b, uint64_t& out)
    {
        if (a > UINT64_MAX - b) return false;
        out = a + b;
        return true;
    }

    static bool safe_sub(uint64_t a, uint64_t b, uint64_t& out)
    {
        if (a < b) return false;
        out = a - b;
        return true;
    }

    static bool safe_mul(uint64_t a, uint64_t b, uint64_t& out)
    {
        if (b != 0 && a > UINT64_MAX / b) return false;
        out = a * b;
        return true;
    }
};

#endif
