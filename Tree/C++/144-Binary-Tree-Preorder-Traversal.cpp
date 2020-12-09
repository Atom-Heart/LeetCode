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
    vector<int> preorderTraversal(TreeNode* root) {
        int white = 0, gray = 1;
        stack<pair<int ,TreeNode*>> st;
        vector<int> ans;
        st.push(make_pair(0, root));
        while(!st.empty()){
            int color = st.top().first;
            TreeNode* node = st.top().second;
            st.pop();
            if(node == nullptr) continue;
            
            if(color == white){
                st.push(make_pair(white, node -> right));
                st.push(make_pair(white, node -> left));
                st.push(make_pair(gray, node));
            }
            else{
                ans.push_back(node -> val);
            }
        }
        return ans;
    }
};