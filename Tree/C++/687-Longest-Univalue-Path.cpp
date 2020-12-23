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
    int ans = 0;//保存全局最大值，这个值去处理特殊情况

    /*递归函数返回从左子树和右子树中返回一个最大的同值节点数*/
    int func(TreeNode* root){
        if(root == nullptr) return 0;
        int left = func(root -> left);
        int right = func(root -> right);

        int Max = 0;//记录root的左右子树中符合要求的最大节点数
        if(root -> left != nullptr && root -> left -> val == root -> val && root -> right != nullptr && root -> right -> val == root -> val){//第一次做的时候在这里卡住了
            ans = max(ans, left + right + 1);
        }

        /*更新当前最大的同值结点数*/
        if(root -> left != nullptr && root -> left -> val == root -> val){
            Max = max(Max, left);
        }
        if(root -> right != nullptr && root -> right -> val == root -> val){
            Max = max(Max, right);
        }
        ans = max(ans, Max + 1);
        return Max + 1;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr) return 0;
        func(root);
        return ans - 1;
    }
};