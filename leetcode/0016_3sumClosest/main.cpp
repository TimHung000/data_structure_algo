#include <vector>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < (int)nums.size()-2; i++) {
            int lo = i + 1;
            int hi = nums.size() - 1;
            while(lo < hi) {
                int value = nums[i] + nums[lo] + nums[hi];

                if(std::abs(value - target) < std::abs(res - target)) {
                    res = value;
                }

                if(value > target)
                    hi--;
                else if(value < target)
                    lo++;
                else
                    return res;
            }
        }
        return res;
    }
}
