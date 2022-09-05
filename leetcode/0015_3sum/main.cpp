#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:

    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        // we only loop through vector length minus 2 because we have to get at least 3 value
        for(int i = 0; i < (int)nums.size()-2; i++) {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int lo = i + 1; //index of second value
                int hi = nums.size() - 1; // index of third value
                int target = 0 - nums[i];
                while(lo < hi) {
                    if(nums[lo] + nums[hi] == target) {
                        res.push_back(std::vector<int>({nums[i], nums[lo], nums[hi]}));
                        while(lo < hi && nums[lo] == nums[lo+1])
                            lo++;
                        while(lo < hi && nums[hi] == nums[hi-1])
                            hi--;
                        lo++;
                        hi--;
                    }
                    else if(nums[lo] + nums[hi] > target)
                        hi--;
                    else
                        lo++;
                }
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    std::vector<int> nums = {};
    Solution sol;
    sol.threeSum1(nums);
    return 0;
}
