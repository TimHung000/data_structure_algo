/**
 * 
 * the implementation of quick select
 * 
 * @author Hao Yu Hung
 * @date   2022/09/30
 */
#include <iostream>
#include <vector>
#include <cassert>
#include <utility>
/**
 * 
 * quickSelect helper function
 * partition arr[left..right], left side of return index in the array are smaller than arr[retval]
 * @retval the index of the partition  
 * @param arr the list of numerics
 * @param left the start index of arr
 * @param right the end index of arr
 *
 */
int partition(std::vector<int>& arr, int left, int right)
{
    int pivotVal = arr[right];

    int currentIdx = left;
    for(int i = left; i < right; ++i)
    {
        if(arr[i] < pivotVal)
        {
            std::swap(arr[i], arr[currentIdx]);
            ++currentIdx;
        }
    }
    std::swap(arr[right], arr[currentIdx]);
    return currentIdx;
} 

/**
 * 
 * find the value of arr[index]
 * 
 * @param arr list of numerics
 * @param kth index of the arr, range from 0 toarr.size()-1
 * 
 */
int quickSelect(std::vector<int> arr, int kth)
{
    if(arr.size() == 1)
    {
        assert(kth == 0);
        return arr[kth];
    }

    int pivotIdx;
    int left = 0;
    int right = arr.size() - 1;
    while(true)
    {
        pivotIdx = partition(arr, left, right);
        if(kth < pivotIdx)
            right = pivotIdx - 1;
        else if(kth > pivotIdx)
            left = pivotIdx + 1;
        else 
            break;
    }
    return arr[pivotIdx];
}

double getMedian(const std::vector<int>& arr)
{
    if(arr.size() == 1)
        return arr[0];
    
    if(arr.size() % 2 == 0)
        return 0.5 * (quickSelect(arr, arr.size()/2-1) + quickSelect(arr, arr.size()/2));
    
    return quickSelect(arr, arr.size()/2);
}

int main(int argc, char** argv)
{
    std::vector<int> arr = {8, 7, 5, 6, 3, 1, 2, 4};
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    
    std::cout << getMedian(arr) << std::endl;
    std::cout << getMedian(arr1) << std::endl;
    return 0;
}