#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if(digits.empty())
            return {};
        std::string map[10] = {
            "",    //0
            "",    //1
            "abc", //2
            "def", //3
            "ghi", //4
            "jkl", //5
            "mno", //6
            "pqrs",//7
            "tuv", //8
            "wxyz" //9
        };

        std::vector<std::string> res({""});

        for(int i = 0; i < digits.size(); i++) {
            std::vector<std::string> tmp;
            std::string s = map[digits[i] - '0'];
            for(int j = 0; j < s.size(); j++) {
                for(int k = 0; k < res.size(); k++) {
                    tmp.push_back(res[k] + s[j]);
                }
            }
            res.swap(tmp);
        }
        return res;
    }

    std::vector<std::string> letterCombinations(std::string digits) {
        if(digits.empty())
            return {};
        std::string map[10] = {
            "",    //0
            "",    //1
            "abc", //2
            "def", //3
            "ghi", //4
            "jkl", //5
            "mno", //6
            "pqrs",//7
            "tuv", //8
            "wxyz" //9
        };

        std::vector<std::string> res;
        std::queue<std::string, std::list<std::string>> myQueue({""});

        while(!myQueue.empty()) {
            std::string curString = myQueue.front();
            myQueue.pop();

            if(curString.size() == digits.size())
                res.push_back(curString);
            else {
                std::string mapString = map[digits[curString.size()] - '0'];
                for(int i = 0; i < mapString.size(); i++)
                    myQueue.push(curString + mapString[i]);
            }
        }
        return res;

    }

};
