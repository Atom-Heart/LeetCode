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
    int ans = INT_MIN;
    /*返回左右子树中最大路径和*/
    int func(TreeNode* root){
        if(root == nullptr) return 0;
        /*这里要和0比较，如果和是负数那就不要了*/
        int leftSum = max(0, func(root -> left));
        int rightSum = max(0, func(root -> right));

        ans = max(ans, root -> val + leftSum + rightSum);
        return root -> val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        func(root);
        return ans;
    }
};