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

/*通过定义来判断，当前节点值大于左子树的最大值，小于右子树的最小值*/
 /*保存三个状态：1.这个子树有没有问题。2.子树的最大值。3.子树的最小值*/
class Solution {
public:
    
    bool isValidBST(TreeNode* root) {
        return inOrder(root)[0];
    }

    vector<int> inOrder(TreeNode* root){
        vector<int> ans = {1, root -> val, root -> val};
        
        if(root -> left){
            auto t = inOrder(root -> left);
            if(t[0] == 0 || root -> val <= t[2]) ans[0] = 0;
            ans[1] = min(t[1], ans[1]);
            ans[2] = max(t[2], ans[2]);
        }

        if(root -> right){
            auto t = inOrder(root -> right);
            if(t[0] == 0 || root -> val >= t[1]) ans[0] = 0;
            ans[1] = min(ans[1], t[1]);
            ans[2] = max(ans[2], t[2]);
        }
        return ans;
    }
};