#include <unordered_map>
#include <iostream>
#include <algorithm>

class Solution {
    public:
        int lengthOfLongestSubstring(std::string s) {
            int currentLength = 0;
            int longestLength = 0;
            int currentStart = 0;
            int start = 0;
            int end = 0;
            std::unordered_map<char, int> umap;
            int size = s.size();
            for(int i = 0; i < size; ++i) {
                std::unordered_map<char, int>::iterator it = umap.find(s[i]);
                if(it == umap.end()) {
                    ++currentLength;
                    umap.insert(std::pair<char, int>(s[i], i));
                    if(currentLength > longestLength) {
                        longestLength = currentLength;
                        end = i;
                        start = currentStart;
                    }
                }
                else {
                    currentLength = 0;
                    currentStart = it->second + 1;
                    i = it->second;
                    umap.clear();
                }
            }
            return longestLength;
        }

        int lengthOfLongestSubstring1(std::string s) {
            std::unordered_map<char, int> umap;
            size_t size = s.size();
            size_t start = 0;
            size_t ret = 0;
            size_t current_length = 0;
            for(int i = 0; i < size; ++i) {
                if(umap.find(s[i]) != umap.end())
                    start = start > umap[s[i]] ? start : umap[s[i]] + 1;
                current_length = i - start + 1;
                ret = ret > current_length ? ret : current_length;
                umap[s[i]] = i;
            }
            return ret;

        }

        int lengthOfLongestSubstring2(std::string s) {
            int map[128];
            std::fill_n(map, 128, -1);
            size_t size = s.size();
            size_t start = 0;
            size_t ret = 0;
            size_t current_length = 0;
            for(int i = 0; i < size; ++i) {
                if(map[s[i]] >= (int)start)
                    start = map[s[i]] + 1;
                current_length = i - start + 1;
                ret = ret > current_length ? ret : current_length;
                map[s[i]] = i;
            }
            return ret;

        }

        int lengthOfLongestSubstring3(std::string s) {
            int map[128] = {0};
            size_t size = s.size();
            size_t ret = 0;
            size_t start = 0;
            for(int i = 0; i < size; ++i) {
                start = std::max(map[s[i]], start);
                ret = std::max(ret, i - start + 1);
                map[s[i]] = i + 1;
            }
            return ret;

        }
};


int main(int argc, char** argv) {
    Solution sol;
    std::string test2 = "tmmzuxt";
    std::cout << sol.lengthOfLongestSubstring2(test2) << std::endl;
    return 0;
}
