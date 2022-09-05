#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        int len = s.length();
        int ret = 0;
        char prev = ' ';
        for(int i = len; i >= 0; i--) {
            if(s[i] == 'I') {
                if(prev != 'V' && prev != 'X')
                    ret = ret + 1;
                else
                    ret = ret - 1;
            }
            else if(s[i] == 'V')
                ret = ret + 5;
            else if(s[i] == 'X') {
                if(prev != 'L' && prev != 'C')
                    ret = ret + 10;
                else
                    ret = ret - 10;
            }
            else if(s[i] == 'L')
                ret = ret + 50;
            else if(s[i] == 'C') {
                if(prev != 'D' && prev != 'M')
                    ret = ret + 100;
                else
                    ret = ret - 100;

            }
            else if(s[i] == 'D')
                ret = ret + 500;
            else if(s[i] == 'M')
                ret = ret + 1000;

            prev = s[i];
        }

        return ret;
    }

    int romanToInt1(std::string s) {
        std::unordered_map<char, int> umap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            if(umap[s[i]] < umap[s[i+1]])
                res -= umap[s[i]];
            else
                res += umap[s[i]];
        }
        return res;
    }

    int romanToInt2(std::string s) {
        int res = 0;
        int prev = 0;
        for(int i = 0; i < s.size(); i++) {
            int value = 0;
            switch(s[i]) {
                case 'I':
                    value = 1;
                    break;
                case 'V':
                    value = 5;
                    break;
                case 'X':
                    value = 10;
                    break;
                case 'L':
                    value = 50;
                    break;
                case 'C':
                    value = 100;
                    break;
                case 'D':
                    value = 500;
                    break;
                case 'M':
                    value = 1000;
                    break;
                default:
                    break;
            }
            res += value;
            if(prev < value)
                res = res - prev * 2;
            prev = value;
        }
        return res;
    }
};


int main(int argc, char *argv[]) {
    std::string test1 = "III";
    std::string test2 = "LVIII";
    std::string test3 = "MCMXCIV";
    Solution sol;
    std::cout << "test1:" << sol.romanToInt1(test1) << std::endl;
    std::cout << "test2:" << sol.romanToInt1(test2) << std::endl;
    std::cout << "test3:" << sol.romanToInt1(test3) << std::endl;
    return 0;
}

