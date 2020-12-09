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
    vector<int> nums;
    int getMinimumDifference(TreeNode* root) {
        InOrder(root);
        int ans = INT_MAX;
        for(int i = 1; i < nums.size(); i++){
            if(ans > nums[i] - nums[i - 1]) ans = nums[i] - nums[i - 1];
        }
        return ans;
    }

    void InOrder(TreeNode* root){
        if(root == nullptr) return;
        InOrder(root -> left);
        nums.push_back(root -> val);
        InOrder(root -> right);
    }
};