#include <string>
#include <iostream>
class Solution {
public:
    std::string intToRoman(int num) {
        const int val[13] = {1000, 900,500,400,100,90,50,40,10,9,5,4,1};
        const std::string roman[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        std::string res;
        int index = 0;
        while(num) {
            while(num >= val[index]) {
                res = res + roman[index];
                num = num - val[index];
            }
            index = index + 1;
        }
        return res;
    }

    std::string intToRoman(int num) {
        std::string digit1[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        std::string digit2[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        std::string digit3[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        std::string digit4[] = {"","M","MM","MMM"};

        return digit4[num/1000] + digit3[(num%1000)/100] + digit2[(num%100)/10] + digit1[(num%10)];
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::cout << sol.intToRoman(3999) << std::endl;
    return 0;
}
