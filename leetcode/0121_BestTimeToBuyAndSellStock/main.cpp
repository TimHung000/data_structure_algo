
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int start = 0;
        int end = 0;
        int current = 0;
        int max = 0;
        int size = prices.size();
        for(int i = 0; i < size; ++i) {
            current = prices[i] - prices[start];
            if(current > max) {
                max = current;
                end = i;
            }
            if(prices[i] < prices[start]) {
                start = i;
            }
        }
        return max;
    }

