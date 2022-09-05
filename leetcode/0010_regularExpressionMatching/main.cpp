#include <string>
#include <vector>

class Solution {
public:
    // recursion
    // time: O((T+P)*2^(T+P/2))?
    // space: O(T^2+P^2)?
    bool isMatch(std::string s, std::string p) {
        if(p.size() == 0)
             return s.size() == 0;

        if(s.size() == 0) {
            //c*c* should return true, otherwise it should return false
            if(p.size() % 2 != 0)
                return false;

            for(int i = 1; i < p.size(); i+=2) {
                if(p[i] != '*')
                    return false;
            }
            return true;
        }

        bool first_match = p[0] == '.' || p[0] == s[0];
        // when there is '*'
        // 1. match the first character from s and keep considering the same '?*' pattern
        // 2. consider '*' as repitive of 0 time
        if(p.size() >= 2 && p[1] == '*') {
            return (first_match && isMatch(s.substr(1), p)) ||
                    isMatch(s, p.substr(2));
        }
        // when second character is not '*' or size is smaller than 2 for p
        // compare the first character of s and p, and advanced both ptr to next char
        else {
            return first_match && isMatch(s.substr(1), p.substr(1));
        }

    }

    // recursion, no edge case
    bool isMatch1(std::string s, std::string p) {
        if(p.size() == 0)
            return s.size() == 0;

        bool first_match = (s.size() > 0) && (p[0] == '.' || p[0] == s[0]);

        if(p.size() >= 2 && p[1] == '*') {
            return (first_match && isMatch(s.substr(1), p)) ||
                    isMatch(s, p.substr(2));
        }
        else {
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }

};

class Solution1 {
public:
    std::string s, p;
    std::vector<std::vector<int>> memo;

    bool isMatch(std::string s, std::string p) {
        this->s = s;
        this->p = p;
        memo = std::vector<std::vector<int>>(s.size()+1, std::vector<int>(p.size()+1, -1));
        return dfs(0,0);
    }

    bool dfs(int i, int j) {
        if(j == p.size())
            return i == s.size();

        if(memo[i][j] != -1) {
            return memo[i][j];
        }

        bool first_match = (i < s.size()) && (p[j] == '.' || p[j] == s[i]);

        if(j+1 < p.size() && p[j+1] == '*') {
            memo[i][j] = (first_match && dfs(i+1, j)) || dfs(i, j+2);
        }
        else {
            memo[i][j] = first_match && dfs(i+1, j+1);
        }

        return memo[i][j];
    }

};
//DP, bottom-up
class Solution2 {
public:
    bool isMatch(std::string s, std::string p) {
        int sLength = s.size();
        int pLength = p.size();
        std::vector<std::vector<bool>> dp(sLength+1, std::vector<bool>(pLength+1, false));

        // s and p are all empty
        dp[0][0] = true;

        //handle the pattern like a*b* with empty string
        for(int j = 1; j <= pLength; ++j) {
            if(j-1 > 0 && p[j-1] == '*')
                dp[0][j] = dp[0][j-2];
        }

        //first column means pattern length == 0, so all elements should be false
        //except string length is 0
        for(int i = 1; i <= sLength; ++i) {
            for(int j = 1; j <= p.size(); ++j) {
                if(p[j-1] == '.' || p[j-1] == s[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2];
                    if(p[j-2] == '.' || p[j-2] == s[i-1]) {
                        dp[i][j] = dp[i-1][j] || dp[i][j];
                    }
                }
            }
        }


        return dp[sLength][pLength];
    }
};

//c solution
bool isMatch(char *s, char *p){
    int i;

    int ls = strlen(s);
    int lp = strlen(p);
    bool* m = malloc((ls + 1) * sizeof(bool));

    // init
    m[0] = true;
    for (i = 1; i <= ls; i++) {
        m[i] = false;
    }

    int ip;
    for (ip = 0; ip < lp; ip++) {
        if (ip + 1 < lp && p[ip + 1] == '*') {
            // do nothing
        }
        else if (p[ip] == '*') {
            char c = p[ip - 1];
            for (i = 1; i <= ls; i++) {
                m[i] = m[i] || (m[i - 1] && (s[i - 1] == c || c == '.'));
            }
        }
        else {
            char c = p[ip];
            for (i = ls; i > 0; i--) {
                m[i] = m[i - 1] && (s[i - 1] == c || c == '.');
            }
            m[0] = false;
        }
    }

    bool ret = m[ls];
    free(m);
    return ret;
}
//c solution, succinct version
bool isMatch(char* s, char* p) {
    while (*s) {
        if (*p&&*(p+1)=='*') {
            if (!(*p==*s||*p=='.')) {p+=2;continue;}
            if (!isMatch(s,p+2)) {s++;continue;} else return true;
        }
        if (*p==*s||*p=='.') {s++;p++;continue;}
        return false;
    }
    while(*p&&*(p+1)=='*') p+=2;
    return !*p;

}
