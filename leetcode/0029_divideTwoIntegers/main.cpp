#include <climits>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
        bool isPositive = dividend >= 0 == divisor >= 0;
        unsigned int absDividend = std::abs(dividend);
        unsigned int absDivisor = std::abs(divisor);
        unsigned int res = 0;
        while(absDividend >= absDivisor) {
            // x is the power of 2
            // assume absDivisor is 3
            // [0]:3*pow(2,1), [1]:3*pow(2,2), [2]:3*pow(2,3), [3]:3*pow(3,4)
            int x = 0;
            while(absDividend > (absDivisor << 1 << x)) {
                x += 1;
            }

            res += 1 << x;
            absDividend -= absDivisor << x;
        }
        if(res == (1<<31) && isPositive)
            return INT_MAX;

        return isPositive ? res : -res;

    }
};

int main(int argc, char** argv) {
    Solution sol;
    sol.divide(INT_MAX, 1);
    sol.divide(INT_MAX, 2);
    sol.divide(INT_MIN, 4);
    return 0;
}
