#include <string>
#include <climits>
#include <iostream>
class Solution {
public:
    int myAtio(std::string s) {

        int res = 0;
        int sign = 1;
        int i = 0;
        //ignore white space
        while(i < s.size() && s[i] == ' ')
            ++i;

        //check the sign
        if(i < s.size() && s[i] == '-' ) {
            sign = -1;
            ++i;
        }
        else if (i < s.size() && s[i] == '+') {
            ++i;
        }
        //INT_MAX = 2147483647
        //INT_MIN = -2147483648
        while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
            // if current digit bigger than 7 means at least 8, so if sign is negative,
            // we can just return INT_MIN
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
                if(sign == 1)
                    return INT_MAX;
                else if(sign == -1)
                    return INT_MIN;
            }
            res = res * 10 + (s[i] - '0');
            ++i;
        }

        return res * sign;

    }
};


int main(int argc, char** argv) {
    std::string test("52");
    std::cout << test << std::endl;
    Solution sol;
    std::cout << sol.myAtio(test) << std::endl;
    return 0;
}
