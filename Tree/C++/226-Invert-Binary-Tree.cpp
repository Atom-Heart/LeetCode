/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*这个题我傻了，想的复杂了，我一开始想的是交换每个节点中的元素，但实际上只要交换每个节点的整体位置就行了*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        TreeNode* temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;

        invertTree(root -> left);
        invertTree(root -> right);
        return root;
        
    }
};