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
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        /*新结点是白色，以访问结点是灰色*/
        /*如果遇到的结点是白色，则将其标记为灰色，然后将右节点，自身，左节点依次入栈*/
        /*如果遇到的结点是灰色，则直接输出*/
        int white = 0;
        int gray = 1;
        stack<pair<int, TreeNode*>> s;
        s.push(make_pair(white, root));
        while(!s.empty()){
            int color = s.top().first;
            TreeNode *t = s.top().second;
            s.pop();
            if(t == NULL){
                continue;
            }
            if(color == white){
                s.push(make_pair(white, t -> right));
                s.push(make_pair(gray, t));
                s.push(make_pair(white, t -> left));
            }
            else{
                ans.push_back(t -> val);
            }
        }
        return ans;
    }
};