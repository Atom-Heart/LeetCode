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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int flag = true;
            while(sz--){
                TreeNode *node = q.front();
                q.pop();
                if(flag){
                    flag = false;
                    ans.push_back(node -> val);
                }
                if(node -> right) q.push(node -> right);
                if(node -> left) q.push(node -> left);
            }
        }
        return ans;
    }
};