#include <vector>
#include <cstddef>
#include <stack>
#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;

        struct TreeNode* res = nullptr;
        struct TreeNode* parent = nullptr;
        struct TreeNode* curPtr = root;
        int find  = 0;

        std::stack<struct TreeNode*> st;

        while(curPtr || !st.empty()) {
            while(curPtr) {
                st.push(curPtr);
                curPtr = curPtr->left;
            }

            curPtr = st.top();
            st.pop();

            if(curPtr == parent) {
                res = curPtr;
                if(!st.empty())
                    parent = st.top();
            }

            if((curPtr == p || curPtr == q) && find == 0) {
                res = curPtr;
                if(!st.empty())
                    parent = st.top(); // parent of current res
                find = 1;
            }
            else if((curPtr == p || curPtr == q) && find == 1) {
                find = 2;
                return res;
            }

            curPtr = curPtr->right;
        }

        return res;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::unordered_map<TreeNode*, TreeNode*> parent;
        std::stack<TreeNode*> st;
        parent.insert(std::make_pair(root,nullptr));
        st.push(root);

        while(parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            TreeNode* curPtr = st.top();
            st.pop();

            if(curPtr->left) {
                parent[curPtr->left] = curPtr;
                st.push(curPtr->left);
            }

            if(curPtr->right) {
                parent[curPtr->right] = curPtr;
                st.push(curPtr->right);
            }
        }

        std::set<TreeNode*> path;
        while(p) {
            path.insert(p);
            p = parent[p];
        }

        while(path.find(q) == path.end()) {
            q = parent[q];
        }

        return q;
    }

    // recursion
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNotde* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor1(root->left, p, q);
        TreeNode* right = lowestCommonAncestor1(root->right, p, q);

        if(left && right)
            return root;

        return left ? left : right;
    }

};

void createTree(TreeNode* node, int i, std::vector<int>& arr) {
    if (node != nullptr) {
        if (2 * i + 1 < arr.size()) {

            if (arr[2 * i + 1] == NULL)
                node->left = nullptr;
            else
                node->left = new TreeNode(arr[2 * i + 1]);

            createTree(node->left, 2 * i + 1, arr);
        }


        if (2 * i + 2 < arr.size()) {
            if (arr[2 * i + 2] == NULL)
                node->right = nullptr;
            else
                node->right = new TreeNode(arr[2 * i + 2]);

            createTree(node->right, 2 * i + 2, arr);
        }
    }
}

TreeNode* levelOrderCreateTree(std::vector<int>& arr) {
    if (arr.size() == 0)
        return nullptr;
    TreeNode *head = new TreeNode(arr[0]);
    createTree(head, 0, arr);
    return head;
}

int main(int argc, char** argv) {

    std::vector<int> test = {2,NULL,1};

    struct TreeNode* myTree = levelOrderCreateTree(test);

    Solution sol;
    struct TreeNode*  res = sol.lowestCommonAncestor(myTree, myTree, myTree->right);

    std::cout << res->val <<std::endl;

    return 0;
}
