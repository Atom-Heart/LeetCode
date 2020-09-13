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
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode *q){
        if((p -> val - root -> val) * (q -> val - root -> val) <= 0){
            return root;
        }
        else if(p -> val > root -> val && q -> val > root -> val){
            return LCA(root -> right, p, q);
        }
        else if(p -> val < root -> val && q -> val < root -> val){
            return LCA(root -> left, p, q);
        }
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p, q);
        
    }
};