/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return std::vector<vector<int>>();
        std::queue<TreeNode*> myqueue;
        std::vector<vector<int>> res;

        myqueue.push(root);
        int level = 0;

        while(!myqueue.empty()) {
            int levelLength = myqueue.size();
            res.push_back(std::vector<int>());

            for(int i = 0; i < levelLength; ++i) {
                root = myqueue.front();
                myqueue.pop();
                res.back().push_back(curPtr->val);
                if(root->left)
                    myqueue.push(root->left);
                if(root->right)
                    myqueue.push(root->right);
            }

            if(level % 2 == 1)
                std::reverse(res.back().begin(), res.back().end());
            ++level;
        }

        for(std::vector<vector<int>>::iterator it = res.begin() + 1; std::distance(res.begin(), it) < res.size(); it = it + 2) {
            std::reverse((*it).begin(), (*it).end());
        }
        return res;
    }
};
