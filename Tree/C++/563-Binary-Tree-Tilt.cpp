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
    int findTilt(TreeNode* root) {
        if(root == nullptr) return 0;
        return abs(func(root -> left) - func(root -> right)) + findTilt(root -> left) + findTilt(root -> right);
    }
    int func(TreeNode* root){
        if(root == nullptr) return 0;
        return root -> val + func(root -> left) + func(root -> right);
    }
};