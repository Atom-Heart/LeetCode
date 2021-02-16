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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            vector<int> temp;
            while(sz--){
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node -> val);
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};