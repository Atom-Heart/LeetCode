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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            TreeNode* node = new TreeNode(v);
            node -> left = root;
            return node;
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> pre;
        int level = 1;
        pre.push_back(root);
        while(!q.empty() && level + 1 != d){
            int sz = q.size();
            pre.clear();
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                if(node && node -> left){
                    q.push(node -> left);
                    pre.push_back(node -> left);
                } 
                if(node && node -> right){
                    q.push(node -> right);
                    pre.push_back(node -> right);
                } 
            }
            level++;
        }

        for(auto node : pre){
            TreeNode* x = new TreeNode(v);
            x -> left = node -> left;
            node -> left = x;

            TreeNode* y = new TreeNode(v);
            y -> right = node -> right;
            node -> right = y;
        }
        return root;
    }
};