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
    TreeNode* helper(vector<int> inorder, int inleft, int inright, vector<int> postorder, int postleft, int postright){
        if(inleft > inright || postleft > postright){
            return nullptr;
        }
        int pivot = postorder[postright];
        TreeNode *root = new TreeNode(pivot);
        int pivotIndex = inleft;
        while(inorder[pivotIndex] != pivot){
            pivotIndex++;
        }

        root -> left = helper(inorder, inleft, pivotIndex - 1, postorder, postleft, postright - (inright - pivotIndex) - 1);
        root -> right = helper(inorder, pivotIndex + 1, inright, postorder, postright - (inright - pivotIndex), postright - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inRight = inorder.size() - 1;
        int postRight = postorder.size() - 1;
        return helper(inorder, 0, inRight, postorder, 0, postRight);
    }
};