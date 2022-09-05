#include <string>
#include <vector>

class Solution {
public:
    // backtracking
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string s;

        helper(res, s, 0, 0, n);
        return res;
    }
    // dynamic programming
    // catalan numbers
    // https://www.youtube.com/watch?v=PBt1gB9Ou9E
    // https://www.youtube.com/watch?v=QdcujZTp_8M
    // https://www.youtube.com/watch?v=m9Khxn2g-6w
    // f(n) is a function which has the set of n matched parantheses
    // f(0) = ''
    // f(1) = (f(0))f(0)
    // f(2) = (f(0))f(1), (f(1))f(0)
    // f(3) = (f(0))f(2), (f(1))f(1), (f(2))f(0)
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::vector<string>> dp(n+1);
        dp[0] = {""};
        for(int i = 1; i <=n; ++i) {
            for(int j = 0; j < i; ++j) {
                for(int k = 0; k < dp[j].size(); ++k) {
                    for(int l = 0; l < dp[i-j-1].size(); ++l) {
                        std::string s = '(' + dp[j][k] + ')' + dp[i-j-1][l];
                        dp[i].push_back(s);
                    }
                }
            }
        }
        return dp[n];
    }

private:
    void helper(std::vector<std::string>& res, std::string& s, int openC, int closeC, int n) {
        if(openC == n && closeC == n) {
            res.push_back(s);
        }

        if(openC < n) {
            s.push_back('(');
            helper(res, s, openC + 1, closeC, n);
            s.pop_back();
        }

        if(closeC < openC) {
            s.push_back(')');
            helper(res, s, openC, closeC + 1, n);
            s.pop_back();
        }

    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<std::string> res = sol.generateParenthesis(1);
    return 0;
}
