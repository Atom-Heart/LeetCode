/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        int x = 0;
        if(root -> left != nullptr && root -> left -> left == nullptr && root -> left -> right == nullptr) x = root -> left -> val;
        return x + sumOfLeftLeaves(root -> left) + sumOfLeftLeaves(root -> right);
    }
};