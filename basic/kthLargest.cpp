#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>

int findKthLargest1(std::vector<int>& nums, int k)
{
    std::sort(nums.begin(), nums.end());
    return nums[nums.size()-k];
}

int findKthLargest2(std::vector<int>& nums, int k)
{
    std::priority_queue<int> pq(nums.begin(), nums.end());
    while(k - 1 > 0)
    {
        pq.pop();
        --k;
    }
    return pq.top();
}

int partition(std::vector<int>& nums, int left, int right)
{
    int pivotValue = nums[right];
    int pos = left;
    for(int i = left; i < right; ++i)
    {
        if(nums[i] < pivotValue)
        {
            std::swap(nums[i], nums[pos]);
            ++pos;
        }
    }
    std::swap(nums[pos], nums[right]);
    return pos;
}

int findKthLargest3(std::vector<int>& nums, int k)
{
    int left = 0;
    int right = nums.size() - 1;
    int targetIndex = nums.size() - k;

    while(left <= right)
    {
        int pivotPos = partition(nums, left, right);
        if(targetIndex > pivotPos)
            left = pivotPos + 1;
        else if(targetIndex < pivotPos)
            right = pivotPos - 1;
        else
            return nums[pivotPos];
    }

    throw NULL;
}

int main()
{
    std::vector<int> arr1 = {1};
    std::cout << findKthLargest3(arr1, 1) << std::endl;
    return 0;
}
