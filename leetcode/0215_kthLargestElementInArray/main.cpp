#include <algorithm>
#include <vector>
#include <iostream>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums.at(nums.size()-k);
    }

    int findKthLargest1(std::vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size() - 1;
        int pivot = findPivotPos(nums, start, end);
        while(pivot != k-1) {
            if(pivot > k-1)
                end = pivot - 1;
            else
                start = pivot + 1;

            pivot = findPivotPos(nums, start, end);
        }

        return nums.at(pivot);
    }

    int findPivotPos(std::vector<int>& nums, int start, int end) {
        int pivot = start;
        int pivot_value = nums.at(start);
        ++start;
        while(start <= end) {
            while(nums.at(start) >= pivot_value) {
                ++start;
                if(start > end) break;
            }
            while(nums.at(end) < pivot_value)
                --end;
            if(start < end) {
                std::swap(nums[start], nums[end]);
                ++start;
                --end;
            }
        }
        std::swap(nums[pivot], nums[end]);
        return end;

    }
};

int main(int argc, char* argv[]) {
    std::vector<int> test_case {5,4,3,6,7,9,10,5,4,5};
    Solution sol;
    std::cout << sol.findKthLargest1(test_case, 1) << std::endl;
    std::cout << sol.findKthLargest1(test_case, 2) << std::endl;
    std::cout << sol.findKthLargest1(test_case, 3) << std::endl;
    std::cout << sol.findKthLargest1(test_case, 4) << std::endl;
    std::cout << sol.findKthLargest1(test_case, 5) << std::endl;
    std::cout << sol.findKthLargest1(test_case, 6) << std::endl;
    std::cout << sol.findKthLargest1(test_case, 7) << std::endl;
    std::cout << sol.findKthLargest1(test_case, 8) << std::endl;
    std::cout << sol.findKthLargest1(test_case, 9) << std::endl;
    std::cout << sol.findKthLargest1(test_case, 10) << std::endl;
}
