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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> res;
        if(!root)
            return res;

        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            res.push_back(q.back()->val);
            for(int i = 0; i < size; ++i) {
                TreeNode* curPtr = q.front();
                q.pop();
                if(curPtr->left)
                    q.push(curPtr->left);
                if(curPtr->right)
                    q.push(curPtr->right);
            }
        }
        return res;

    }
    //pre-order traversal using recursion
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> res;
        helper(root, 0, res);
        return res;
    }

    void helper(TreeNode* root, int level, std::vector<int>& res) {
        if(!root)
            return;
        if(res.size() <= level)
            res.push_back(NULL);

        res[level] = root->val;

        helper(root->left, level + 1, res);
        helper(root->right, level + 1, res);
    }
};
