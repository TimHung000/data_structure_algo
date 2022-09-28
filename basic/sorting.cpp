/**
 * 
 * @author Hao Yu Hung
 * @date   2022/09/28
 * 
 * The implementation of sorting algo
 * 
 */
#include <iostream>
#include <utility> /* std::swap */
#include <vector>

/**
 * sort int array in non-decreasing order
 * 
 * @param arr the array be sorting
 * @param size the elements of the array
 * 
 */
void bubbleSort(int arr[], int size)
{
    /* check if there is a swap in this round, if not, all elements are sorted */
    int flag;

    for(int i = 0; i < size - 1; ++i)
    {
        flag = 0;
        for(int j = 0; j < size - i; ++j)
        {
            if(arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}

/**
 * sort int array in non-decreasing order
 * 
 * @param arr the array be sorting
 * @param size the elements of the array
 * 
 */
void insertionSort(int arr[], int size)
{
    /* start from the second ele cause one ele array is already sorted */
    for(int i = 1; i < size; ++i)
    {
        int currentVal = arr[i];
        int j = i - 1;
        while(j >= 0 && currentVal < arr[j])
        {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = currentVal;
    }
}

/**
 * sort int array in non-decreasing order
 * 
 * @param arr the array be sorting
 * @param size the elements of the array
 * 
 */
void selectionSort(int arr[], int size)
{
    for(int i = 0; i < size - 1 ; ++i)
    {
        int minIndex = i;
        for(int j = i + 1; j < size; ++j)
        {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }

        std::swap(arr[minIndex], arr[i]);
    }
}

/**
 * mergeSort Helper function
 * 
 * @param arr the array to be sorted
 * @param left,mid,right two subarray to be merged arr[left..mid] and arr[mid+1..right] 
 */
void merge(std::vector<int>& arr, const int left, const int mid, const int right)
{
    std::vector<int> leftSubArr(arr.begin()+left, arr.begin()+mid+1);
    std::vector<int> rightSubArr(arr.begin()+mid+1, arr.begin()+right+1);

    int leftSubArrIndex = 0;
    int rightSubArrIndex = 0;
    int mergedArrIndex = left;
    

    while(leftSubArrIndex < leftSubArr.size() && rightSubArrIndex < rightSubArr.size())
    {
        if(leftSubArr[leftSubArrIndex] <= rightSubArr[rightSubArrIndex])
        {
            arr[mergedArrIndex] = leftSubArr[leftSubArrIndex];
            ++leftSubArrIndex;
        }
        else
        {
            arr[mergedArrIndex] = rightSubArr[rightSubArrIndex];
            ++rightSubArrIndex;
        }
        ++mergedArrIndex;
    }
    
    while(leftSubArrIndex < leftSubArr.size())
    {
        arr[mergedArrIndex] = leftSubArr[leftSubArrIndex];
        ++leftSubArrIndex;
        ++mergedArrIndex;
    }

    while(rightSubArrIndex < rightSubArr.size())
    {
        arr[mergedArrIndex] = rightSubArr[rightSubArrIndex];
        ++rightSubArrIndex;
        ++mergedArrIndex;
    }
}

/**
 * sort int array in non-decreasing order
 * 
 * @param arr the array to be sorted(arr[left..right])
 * @param left the index of the starting ele.
 * @param right the index of the end ele.
 * 
 */
void mergeSort(std::vector<int>& arr, const int left, const int right)
{
    if(left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

/**
 * quick sort helper function
 * 
 * @param left
 * @param right
 * 
 */
int partition(std::vector<int>&arr, const int left, const int right)
{
    int pivotVal = arr[right];
    int index = left;
    for(int i = left; i < right; ++i)
    {
        if(arr[i] < pivotVal)
        {
            std::swap(arr[index], arr[i]);
            ++index;
        }
    }
    std::swap(arr[index],arr[right]);
    return index;
}

/**
 * sort int array in non-decreasing order
 * 
 * @param arr the array to be sorted(arr[left..right])
 * @param left the index of the starting element.
 * @param right the index of the end element.
 * 
 */
void quickSort(std::vector<int>& arr, const int left, const int right)
{
    if(left >= right)
        return;
    
    int pivot = partition(arr, left, right);
    quickSort(arr, left, pivot-1);
    quickSort(arr, pivot+1, right);
}

void printVec(std::vector<int>& arr)
{
    for(int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printArr(int arr[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main(int argc, char** argv)
{
    int arr[5] = { 3, 2 ,2, 5, 4};
    std::vector<int> arr1 = {3, 2, 2, 5, 4};
    quickSort(arr1, 0, arr1.size()-1);
    printVec(arr1);

}