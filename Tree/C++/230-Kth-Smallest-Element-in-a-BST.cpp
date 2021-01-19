/*方法一：递归*/
class Solution {
public:
    int cnt = 0;
    int ans;
    void inOrder(TreeNode *root, int k){
        if(root == nullptr) return;
        
        inOrder(root -> left, k);
        cnt++;
        if(k == cnt){
            ans = root -> val;
            return;
        }
        inOrder(root -> right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return ans;
    }
};