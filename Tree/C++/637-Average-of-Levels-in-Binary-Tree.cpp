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
    vector<double> ans;
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            double sz = st.size();
            double ave = 0;
            int n = sz;
            while(n--){
                TreeNode* node = st.front();
                st.pop();
                ave += node -> val;
                if(node -> left) st.push(node -> left);
                if(node -> right) st.push(node -> right);
            }
            ans.push_back(ave / sz);
        }
        return ans;
    }
};