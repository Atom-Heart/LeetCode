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
    int Max(vector<int>& nums, int left, int right){
        int ans = INT_MIN;
        int idx = -1;
        for(int i = left; i <= right; i++){
            if(nums[i] > ans){
                ans = nums[i];
                idx = i;
            }
        }
        return idx;
    }
    TreeNode* func(vector<int>& nums, int left, int right){
        if(left > right) return nullptr;
        int idx = Max(nums, left, right);
        int num = nums[idx];
        TreeNode* root = new TreeNode(num);
        root -> left = func(nums, left, idx - 1);
        root -> right = func(nums, idx + 1, right);
        return root;   
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return func(nums, 0, nums.size() - 1);
    }
};