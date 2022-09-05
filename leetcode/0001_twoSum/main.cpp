#include <iostream>
#include <unordered_map>
#include <vector>
#include <iterator>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> umap;
        std::vector<int> ret;
        ret.reserve(2);

        for(std::vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
            std::unordered_map<int, int>::iterator umap_it = umap.find(target - *it);

            if(umap_it != umap.end()) {
                ret.push_back(umap_it -> second);
                ret.push_back(it-nums.begin());
                break;
            }

            umap.insert(std::pair<int, int>(*it ,it-nums.begin()));
        }
        return ret;
    }

    std::vector<int> twoSum1(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> umap;
        std::vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            auto targetPtr = umap.find(target - nums[i]);
            if(targetPtr != umap.end()) {
                res.push_back(i);
                res.push_back(targetPtr->second);
                break;
            }
            umap[nums[i]] = i;
        }
        return res;
    }
};

void print_vector(std::vector<int>& vect) {
}

int main(int argc, char** argv) {

    std::vector<int> test_case1{1,2,3,4,5,6,7,8,9};
    std::vector<int> test_case2{5,5,5,5};
    std::vector<int> test_case3{3,3,3,7};
    std::vector<int> test_case4{2,7,11,15};
    Solution sol;
    sol.twoSum1(test_case4, 9);
    return 0;

}
