#include <vector>
#include <algorithm>
#include <set>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> res;
        int size = nums.size();
        if(size < 4)
            return res;

        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < size - 3; ++i) {
            // target is bigger than the smallest value in this round
            if(target <= 0 && nums[i] > 0) break;

            if((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            // nums[i] is too small so get to next i
            if((long long)nums[i] + nums[size-3] + nums[size-2] + nums[size-1] < target) continue;

            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i + 1; j < size - 2; ++j) {
                /* Some more pruning */
                // nums[j] has become too large, no point in continuing
                if ((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                // nums[j] is so small, even the largest elements cannot help reach the sum
                if ((long long)nums[i] + nums[j] + nums[size-2] + nums[size-1] < target) continue;
                if (j > i+1 && nums[j] == nums[j-1]) continue;

                int lo = j + 1;
                int hi = size - 1;
                while(lo < hi) {
                    long long sum = (long long)nums[i] + nums[j] + nums[lo] + nums[hi];
                    if(sum == target) {
                        res.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        ++lo;
                        --hi;
                        while(lo < hi && nums[lo] == nums[lo-1]) ++lo;
                        while(lo < hi && nums[hi] == nums[hi+1]) --hi;
                    }
                    else if(sum < target)
                        ++lo;
                    else
                        --hi;
                }
            }
        }
        return res;
    }
};

class Solution1 {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }

    std::vector<std::vector<int>> kSum(std::vector<int>& nums, int target, int start, int k) {
        std::vector<std::vector<int>> res;

        // If we have run out of numbers to add, return res.
        if (start == nums.size()) {
            return res;
        }

        // There are k remaining values to add to the sum. The
        // average of these values is at least target / k.
        int average_value = target / k;

        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest
        // value in nums is smaller than target / k.
        if  (nums[start] > average_value || average_value > nums.back()) {
            return res;
        }

        if (k == 2) {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                std::vector<std::vector<int>> subRes = kSum(nums, target-nums[i], i+1, k-1);
                for(int j = 0; j < subRes.size(); j++) {
                    res.push_back({nums[i]});
                    res.back().insert(std::end(res.back()), std::begin(subRes[j]), std::end(subRes[j]));
                }
            }
        }

        return res;
    }

    std::vector<std::vector<int>> twoSum(std::vector<int>& nums, int target, int start) {
        std::vector<std::vector<int>> res;
        int lo = start, hi = nums.size() - 1;

        while (lo < hi) {
            int curr_sum = nums[lo] + nums[hi];
            if (curr_sum < target || (lo > start && nums[lo] == nums[lo - 1])) {
                ++lo;
            } else if (curr_sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) {
                --hi;
            } else {
                res.push_back({ nums[lo++], nums[hi--] });
            }
        }

        return res;
    }
};


int main(int argc, char** argv) {
    std::vector<int> test({2,2,2,2,2,2});
    Solution sol;
    sol.fourSum(test, 8);
}
