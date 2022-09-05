#include <string>
#include <iostream>

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int carry = 0;
        std::string res = "";

        for(int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; --i, --j) {
            int first = i >= 0 ? num1[i] - '0' : 0;
            int second = j >=0 ? num2[j] - '0' : 0;
            int sum = first + second + carry;
            carry = sum / 10;
            res.insert(res.begin(),sum % 10 + '0');
        }

        if(carry)
            res.insert(res.begin(), '1');

        return res;

    }
};


int main(int argc, char** argv) {
    std::string a = "11";
    std::string b = "123";
    Solution sol;
    std::cout << sol.addStrings(a, b) << std::endl;
    return 0;

}
