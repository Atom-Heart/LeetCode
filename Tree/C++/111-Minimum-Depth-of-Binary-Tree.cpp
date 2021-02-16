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
    int level = 1;
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        level = 2;
        int left = minDepth(root -> left);
        int right = minDepth(root -> right);
        level = 1;
        if(level == 1){
            if((left == 0 && right != 0) || (left != 0 && right == 0)){
                return max(left, right) + 1;
            }
        }
        return min(left, right) + 1;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root -> left == nullptr && root -> right == nullptr) return 1;
        int x = minDepth(root -> left);
        int y = minDepth(root -> right);
        return root -> left == nullptr || root -> right == nullptr ? x + y + 1 : min(x, y) + 1;
    }
};