//time complexity : O(n*m)
class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if(!needle.size())
            return 0;

        for(int i = 0; i < haystack.size(); ++i) {
            if(haystack[i] == needle[0]) {
                if(needle == haystack.substr(i, needle.size()))
                    return i;
            }
        }
        return -1;
    }

};
//time complexity : O(n*m)
class Solution1 {
public:
    int strStr(std::string haystack, std::string needle) {
        if(needle == "")
            return 0;
        int n = haystack.size() - needle.size() + 1;
        for(int i = 0; i < (int)haystack.size() - (int)needle.size() + 1; ++i) {
            for(int j = 0; j < needle.size(); ++j) {
                if(haystack[i+j] != needle[j])
                    break;
                if(j == needle.size() - 1)
                    return i;
            }
        }
        return -1;
    }
}

/*
 * https://www.youtube.com/watch?v=JoF0Z7nVSrA&t=28s
 * KMP(knuth Morris Pratt) Pattern Searching
 * lps(longest prefix suffix) array
 *
 * time complexity : O(n+m), space complexity : O(m)
*/
class Solution2 {
public:
    int strStr(std::string haystack, std::string needle) {
        if(needle == "")
            return 0;
        int *lps = new int[needle.size()] {};

        // creating lps array
        int prevLPS = 0;
        int i = 1;
        while(i < needle.size()) {
            if(needle[i] == needle[prevLPS]) {
                lps[i] = prevLPS + 1;
                prevLPS += 1;
                i += 1;
            }
            else if(prevLPS == 0) {
                lps[i] = 0;
                i += 1;
            }
            else {
                prevLPS = lps[prevLPS-1];
            }
        }

        //KMP pattern searching
        i = 0;
        int j = 0;
        while(i < haystack.size()) {
            if(haystack[i] == needle[j]) {
                i += 1;
                j += 1;
            }
            else {
                if(j == 0)
                    i += 1;
                else
                    j = lps[j-1];
            }

            if(j == needle.size()) {
                delete[] lps;
                return i-needle.size();
        }
        delete[] lps;
        return -1;
    }
}
