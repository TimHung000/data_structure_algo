class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int i = 0;
        for(int n : nums) {
            if(!i || n > nums[i-1])
                nums[i++] = n;
        }
        return i;
    }

    int removeDuplicates(std::vector<int>& nums) {
        int count = 0;
        auto it = std::unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        return nums.size();
    }

    int removeDuplicates(std::vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i-1]) {
                nums.erase(nums.begin()+i);
                --i;
            }
        }
        return nums.size();
    }

    int removeDuplicates(std::vector<int>& nums) {
        if(!nums.size())
            return 0;
        int ptr = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[ptr] != nums[i]) {
                ++ptr;
                nums[ptr] = nums[i];
            }
        }
        return ptr+1;
    }

};
