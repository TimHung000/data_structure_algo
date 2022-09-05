#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::string res("");
        int resLength = 0;
        int size = s.size();

        for(int i = 0; i < size; i++) {
            // odd length palindrome
            int left = i;
            int right = i;
            int curLength = 0;
            while(left >= 0 && right < size && s[left] == s[right]) {
                curLength = right - left + 1;
                if(curLength > resLength) {
                    res.assign(s, left, curLength);
                    resLength = curLength;
                }
                --left;
                ++right;
            }

            // even length palindrome
            left = i;
            right = i + 1;
            curLength = 0;
            while(left >=0 && right < size && s[left] == s[right]) {
                curLength = right - left + 1;
                if(curLength > resLength) {
                    res.assign(s, left, curLength);
                    resLength = curLength;
                }
                --left;
                ++right;
            }
        }
        return res;
    }

    //DP
    std::string longestPalindrome(std::string s) {
        if(s.size() == 0)
            return std::string();

        // dp[i][j] will be 'true' if the string index from i to j is a palindrome
        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));
        int sLength = s.size();

        // all length 1 string are palindrome
        for(int i = 0; i < sLength; ++i) {
            dp[i][i] = true;
        }

        std::string res(s, 0, 1);

        for(int start = sLength - 1; start >= 0; --start) {
            for(int end = start + 1; end < sLength; ++end) {
                if(s[start] == s[end]) {
                    // if it's consecutive two char or it's inner string is palindrome
                    int curLen = end - start + 1;
                    if(curLen == 2 || dp[start+1][end-1]) {
                        dp[start][end] = true;

                        if(curLen >= res.size())
                            res.assign(s, start, curLen);
                    }
                }
            }
        }
        return res;
    }
};
