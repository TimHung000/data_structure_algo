#include <iostream>
#include <vector>
#include <string> // std::string, std::to_string
#include <cmath> // std::log10
#include <cstdbool> // bool
#include <climits>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;

        std::vector<int> ary;
        bool result = true;

        while(x) {
            ary.push_back(x % 10);
            x /= 10;
        }

        int left = 0;
        int right = 0;

        if(ary.size() % 2) {
            left = ary.size() / 2;
            right = ary.size() / 2;
        }
        else {
            left = ary.size() / 2 - 1;
            right = ary.size() / 2;
        }

        while(left >=0 && right < ary.size()) {
            if(ary[left] != ary[right]) {
                result = false;
                break;
            }
            --left;
            ++right;
        }

        return result;
    }
    // cheating
    bool isPalindrome1(int x) {
        std::string s = std::to_string(x);
        bool result = s == std::string(rbegin(s), rend(s));
        return result;

    }

    bool isPalindrome3(int x) {
        std::string s = std::to_string(x);
        for(int i = 0; i < s.size() / 2; ++i) {
            if(s[i] != s[s.size() - i - 1])
                return false;
        }
        return true;
    }

    bool isPalindrome2(int x) {
        if(x < 0)
            return false;
        if(x == 0) //std::log10 can't take parameter 0
            return true;
        int length = static_cast<int>(std::log10(x) + 1);
        int divisor = std::pow(10, length - 1);
        for(int i = 0 ; i < length / 2; ++i) {
            if(x / divisor != x % 10)
                return false;
            x = (x - x / divisor * divisor) / 10;
            divisor /= 100;
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::cout << static_cast<int>(std::log10(INT_MAX)) << std::endl;
    std::cout << sol.isPalindrome3(0) << std::endl;
    std::cout << sol.isPalindrome3(12321) << std::endl;
    std::cout << sol.isPalindrome3(123321) << std::endl;
    std::cout << sol.isPalindrome3(-123321) << std::endl;
    return 0;

}

