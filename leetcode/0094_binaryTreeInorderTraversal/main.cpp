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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        inorder(root, res);
        return res;
    }

    void traversal(TreeNode* root, std::vector<int>& res) {
        if(!root)
            return;
        traversal(root->left, res);
        res.push_back(root->val);
        traversal(root->right, res);
    }

    vector<int> inorderTraversal1(TreeNode* root) {
        std::vector<int> res;
        std::stack<struct TreeNode*> st;
        struct TreeNode* ptr = root;
        while(ptr || !st.empty()) {
            while(ptr) {
                st.push(ptr);
                ptr = ptr->left;
            }
            res.push_back(st.top()->val);
            ptr = st.top()->right;
            st.pop();
        }
        return res;

    }
};
