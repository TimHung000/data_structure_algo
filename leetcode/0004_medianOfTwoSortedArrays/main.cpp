#include <vector>
#include <algorithm>
#include <climits> //INT_MAX, INT_MIN

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        //elements to median or left median
        int median = (nums1.size() + nums2.size() + 1) / 2;

        int left = 0;
        int right = nums1.size();

        while(left <= right) {
            int partition1 = (left + right ) / 2;
            int partition2 = median - partition1;

            int leftNums1 = partition1 <= 0 ? INT_MIN : nums1[partition1 - 1];
            int rightNums1 = partition1 >= nums1.size() ? INT_MAX : nums1[partition1];
            int leftNums2 = partition2 <= 0 ? INT_MIN :nums2[partition2 - 1];
            int rightNums2 = partition2 >= nums2.size() ? INT_MAX : nums2[partition2];

            if(leftNums1 <= rightNums2 && leftNums2 <= rightNums1) {
                if((nums1.size() + nums2.size()) % 2) {
                    return std::max(leftNums1, leftNums2);
                }
                else {
                    return ((double)std::max(leftNums1, leftNums2)
                            + (double)std::min(rightNums1, rightNums2)) / 2;
                }
            }
            else if(leftNums1 > rightNums2) {
                right = partition1 - 1;
            }
            else {
                left = partition1 + 1;
            }

        }
        return -1;
    }
};
