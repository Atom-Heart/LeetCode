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
    int route = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;   
        route += root -> val;

        if(root -> left == nullptr && root -> right == nullptr && route == targetSum) return true;

        if(hasPathSum(root -> left, targetSum)) return true;
        if(hasPathSum(root -> right, targetSum)) return true;
        route -= root -> val;
        return false;
    }
};