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
    vector<TreeNode*> helper(int begin, int end){
        vector<TreeNode*> res;
        if(begin > end){
            res.push_back(nullptr);
        }
        for(int i = begin; i <= end; i++){
            vector<TreeNode*> left = helper(begin, i - 1);
            vector<TreeNode*> right = helper(i + 1, end);
            for(auto l : left){
                for(auto r : right){
                    TreeNode* root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if(n == 0) return {ans};
        ans = helper(1, n); 
        return ans;
    }
};