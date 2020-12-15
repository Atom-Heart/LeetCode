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
    vector<int> vec;
    void Inorder(TreeNode* root){
        if(root == nullptr) return;
        Inorder(root -> left);
        vec.push_back(root -> val);
        Inorder(root -> right);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        Inorder(root);
        int left = 0, right = vec.size() - 1;
        while(left < right){
            int sum = vec[left] + vec[right];
            if(sum < k){
                left++;
            }
            else if(sum > k){
                right--;
            }
            else{
                return true;
            }
        }
        return false;
    }
};