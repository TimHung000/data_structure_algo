#include <string>
class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if(numRows <= 1)
            return s;
        std::string ary[numRows];
        std::string res;
        int sLength = s.size();
        int curRow = 0;
        char reverse = 0;
        for(int i = 0; i < sLength; ++i) {

            ary[curRow].push_back(s[i]);

            if(reverse)
                --curRow;
            else
                ++curRow;

            if(curRow == numRows) {
                reverse = !reverse;
                curRow = curRow - 2;
            }

            if(curRow == -1) {
                reverse = !reverse;
                curRow = curRow + 2;
            }
        }

        for(int i = 0; i < numRows; ++i) {
            res.append(ary[i]);
        }
        return res;
    }

    std::string convert(std::string s, int numRows) {
        if(numRows <= 1)
            return s;

        std::string res;
        for(int i = 0; i < numRows; ++i) {
            int increment = (numRows - 1) * 2;

            for(int j = i; j < s.size(); j = j + increment) {
                res.push_back(s[j]);
                if(i > 0 && i < numRows - 1 && j + increment - 2 * i < s.size())
                    res.push_back(s[j + increment - 2 * i]);
            }
        }

        return res;
    }

};
