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
    vector<vector<int>> ans;
    vector<int> route;
    int sum = 0;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }

    void dfs(TreeNode* root, int targetSum){
        if(root == nullptr) return;

        route.push_back(root -> val);
        sum += root -> val;
        
        if(root -> left == nullptr && root -> right == nullptr){
            if(sum == targetSum){
                ans.push_back(route);
            }
        }

        dfs(root -> left, targetSum);
        dfs(root -> right, targetSum);
        
        route.pop_back();
        sum -= root -> val;
    }
};