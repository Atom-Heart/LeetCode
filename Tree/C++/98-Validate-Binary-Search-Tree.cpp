/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*BST中序遍历的结果时升序的，所以只要判断当前节点元素是不是大于上一个节点元素就行了，如果一旦发现不是BST，要及时
 进行剪枝操作*/
class Solution {
public:
    long pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        
        if(!isValidBST(root -> left)) return false;
        if(root -> val <= pre) return false;
        pre = root -> val;
        return isValidBST(root -> right);
    }
};