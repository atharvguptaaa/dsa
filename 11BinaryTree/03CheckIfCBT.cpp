// Check if a given binary tree is a complete binary tree.

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    //BFS APPROACH
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        bool isNullNode = false;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp == nullptr) {
                isNullNode = true;
            } else {
                if (isNullNode) {
                    return false;  // If we encounter a non-null node after a null node, it's not complete.
                }
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return true;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution s;
    cout << (s.isCompleteTree(root) ? "true" : "false") << endl;

    return 0;
}
