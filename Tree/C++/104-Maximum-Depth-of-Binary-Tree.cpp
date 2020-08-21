/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*递归思想，想求一棵树的最大深度，那就是取左右子树中最大的高度然后加1，那么就需要递归求解左右子树的高度了*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);
        return max(left, right) + 1;
    }
};