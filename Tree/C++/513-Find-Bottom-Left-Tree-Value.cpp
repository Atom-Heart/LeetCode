/*一开始还求了个树的深度，没有必要*/
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
    /*求出树的深度*/
    int helper(TreeNode* root){
        if(root == nullptr) return 0;
        int x = max(helper(root -> left), helper(root -> right)) + 1;
        return x;
    }

    int bfs(TreeNode* root, int d){
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int ans = -1;
        while(!q.empty()){
            if(level == d){
                ans = q.front() -> val;
                break;
            }
            int sz = q.size();
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                if(node -> left != nullptr) q.push(node -> left);
                if(node -> right != nullptr) q.push(node -> right);
            }
            level++;
        }
        return ans;
    }

    int findBottomLeftValue(TreeNode* root) {
        int d = helper(root);
        return bfs(root, d);
    }
};

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = -1;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                TreeNode* node = q.front();
                q.pop();
                /*每次都将ans变成每一层的第一个结点的值*/
                if(i == 0) ans = node -> val;
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
        }
        return ans;
    }
};