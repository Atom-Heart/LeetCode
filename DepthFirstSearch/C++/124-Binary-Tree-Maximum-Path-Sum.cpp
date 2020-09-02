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
    int res = INT_MIN;
    int DFS(TreeNode* root){
        if(root == nullptr) return 0;
        int leftMax = max(0, DFS(root -> left));
        int rightMax = max(0, DFS(root -> right));
        res = max(res, root -> val + leftMax + rightMax);
        return root -> val + max(leftMax, rightMax);
    }
    int maxPathSum(TreeNode* root) {
        DFS(root);
        return res;
    }
};