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
    vector<TreeNode*> ans;
    unordered_map<string, int> mp;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        inOrder(root);
        return ans;
    }

    string inOrder(TreeNode *root){
        if(root == nullptr) return "#";
        string str = to_string(root -> val) + ' ' + inOrder(root -> left) + ' ' + inOrder(root -> right);
        if(mp[str] == 1) ans.push_back(root);
        mp[str]++;
        return str;
    }
};