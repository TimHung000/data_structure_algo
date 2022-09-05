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

    vector<int> levelOrder(TreeNode* root) {
        std::queue<std::pair<struct TreeNode*, int>> myQueue;
        std::vector<std::vector<int>> res;
        std::vector<int> subRes;
        struct TreeNode* curPtr;
        int curLevel = 0;
        int level = 0;

        if(root) {
            myQueue.push(std::make_pair(root, curLevel));
            while(!myQueue.empty()) {
                curPtr = myQueue.front().first;
                curLevel = myQueue.front().second;
                myQueue.pop();

                if(curPtr->left)
                    myQueue.push(std::make_pair(curPtr->left, curLevel + 1));
                if(curPtr->right)
                    myQueue.push(std::make_pair(curPtr->right, curLevel + 1));

                if(curLevel != level) {
                    res.push_back(subRes);
                    subRes.clear();
                    ++level;
                }

                subRes.push_back(curPtr->val);
            }
            res.push_back(subRes);
        }

        return res;
    }

    // BFS Implementation
    vector<int> levelOrder(TreeNode* root) {

        if(!root)
            return std::vector<vector<int>>();

        std::vector<std::vector<int>> res;

        std::queue<struct TreeNode*> myQueue;
        myQueue.push(root);

        struct TreeNode *curPtr = nullptr;
        int levelLength = 0;

        while(!myQueue.empty()) {
            levelLength = myQueue.size();
            res.push_back(std::vector<int>());
            for(int i = 0; i < levelLength; ++i) {
                curPtr = myQueue.front();
                myQueue.pop();
                res.back().push_back(curPtr->val);
                if(curPtr->left)
                    myQueue.push(curPtr->left);
                if(curPtr->right)
                    myQueue.push(curPtr->right);
            }
        }
        return res;
    }


};
