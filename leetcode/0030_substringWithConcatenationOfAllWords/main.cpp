#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> res;
        int sLength = s.size();
        int wordCnt = words.size();

        if(sLength == 0 || wordCnt == 0)
            return res;

        std::unordered_map<std::string, int> umap;
        for(int i = 0; i < wordCnt; ++i) {
            umap[words[i]] += 1;
        }

        int wLength = words[0].size();

        for(int i = 0; i < sLength - wLength * wordCnt + 1; ++i) {
            std::unordered_map<std::string, int> copy(umap);
            int ptr = i;  // point to the first char of the s that are going to compare to word
            int j = 0;    // traverse all words in vector(words)
            while(j < wordCnt) {
                std::string str = s.substr(ptr, wLength);
                if(copy.find(str) == copy.end() || copy[str] == 0)
                    break;

                copy[str]--;
                ptr += wLength;
                j++;
            }

            if(j == wordCnt)
                res.push_back(i);
        }
        return res;
    }
}
