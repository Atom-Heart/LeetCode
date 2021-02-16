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
 /*树的路径回溯*/
class Solution {
public:
    vector<string> nums;
    string route;
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        int ans = 0;
        for(auto num : nums){
            ans += stoi(num);
        }
        return ans;
    }
    void dfs(TreeNode* root){
        route += ('0' + root -> val);
        if(root -> left == nullptr && root -> right == nullptr){
            nums.push_back(route);
            return; 
        }
        
        if(root -> left){
            dfs(root -> left);
            route.pop_back();
        } 
        if(root -> right){
            dfs(root -> right);
            route.pop_back();
        }
    }
};


/*分治*/
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
    int helper(TreeNode* root, int sum){
        if(!root) return 0;
        if(!root -> left && !root -> right) return sum * 10 + root -> val;
        return helper(root -> left, sum * 10 + root -> val) + helper(root -> right, sum * 10 + root -> val);
    }
};