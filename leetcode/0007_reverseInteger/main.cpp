#include <climits>
#include <iostream>

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x) {
            int remainder = x % 10;
            if(res > INT_MAX / 10 || res < INT_MIN / 10)
                return 0;
            res = res * 10 + remainder;
            x /= 10;
            std::cout << res << std::endl;
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::cout << sol.reverse(-1463847412) << std::endl;
    std::cout << INT_MIN << std::endl;
    return 0;
}
