class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int ptr = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != val)
                nums[ptr++] = nums[i];
        }
        return ptr;
    }

    int removeElement(std::vector<int>& nums, int val) {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};
