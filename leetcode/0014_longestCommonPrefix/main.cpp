#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if(!strs.size())
            return "";

        std::string res;
        // index of char
        for(int i = 0; i < strs[0].size(); i++) {
            char x = strs[0][i];
            //index of vector
            for(int j = 1; j < strs.size(); j++) {
                if(x != strs[j][i]){
                    return res;
                }
            }
            res.push_back(strs[0][i]);
        }

        return res;
    }

    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if(!strs.size())
            return "";
        int vectorLength = strs.size();
        std::string res;
        // can't change the parameter
        // std::vector<std::string> myStrs = strs;
        sort(strs.begin(), strs.end());
        std::string string1 = strs[0];
        std::string string2 = strs[vectorLength - 1];
        for(int i = 0; i < string1.size(); i++) {
            if(string1[i] != string2[i])
                break;
            res.push_back(string1[i]);
        }
        return res;
    }
}
