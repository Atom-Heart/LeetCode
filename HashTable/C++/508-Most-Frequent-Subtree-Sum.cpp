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
    unordered_map<int, int> hash;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        int Max = INT_MIN;
        for(auto [k, v] : hash){
            //cout<<v<<endl;
            if(v > Max) Max = v;
        }
        
        vector<int> ans;
        for(auto [k, v] : hash){
            if(v == Max) ans.push_back(k);
        }
        return ans;
    }
    int helper(TreeNode* root){
        if(root == nullptr) return 0;
        int x = helper(root -> left);
        int y = helper(root -> right);
        int z = root -> val + x + y;
        hash[z]++;
        return z;
    }
};