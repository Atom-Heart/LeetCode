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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        int direction = 0;
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
            if(direction == 0){
                ans.push_back(temp);
                direction = 1;
            }
            else{
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                direction = 0;
            }
        }
        return ans;
    }
};