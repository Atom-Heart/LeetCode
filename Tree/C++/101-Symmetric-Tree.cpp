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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            vector<int> level;
            while(sz--){
                TreeNode *node = q.front();
                q.pop();
                if(node == nullptr){
                    level.push_back(-1);
                    continue;
                }
                level.push_back(node -> val);
                q.push(node -> left);
                q.push(node -> right);
            }

            int left = 0, right = level.size() - 1;
            while(left < right){
                if(level[left++] != level[right--]) return false;
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return dfs(root, root);
    }
    bool dfs(TreeNode *node1, TreeNode *node2){
        if(node1 == nullptr && node2 == nullptr) return true;
        if(node1 == nullptr || node2 == nullptr) return false;

        return node1 -> val == node2 -> val && dfs(node1 -> left, node2-> right) && dfs(node1 -> right, node2 -> left);
    }
};