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

 /*找到第一个比根节点大的值*/
class Solution {
public:
    int func(TreeNode* node, int val){
        if(node == nullptr) return -1;
        if(node -> val > val) return node -> val;
        int left = func(node -> left, val);
        int right = func(node -> right, val);
        if(left == -1) return right;
        if(right == -1) return left;
        return min(left, right);   
    }
    int findSecondMinimumValue(TreeNode* root) {
        return func(root, root -> val);

    }
};