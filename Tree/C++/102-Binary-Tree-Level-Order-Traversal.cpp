/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*之前的写的层次遍历是每次处理一个节点，把这个节点的数读出来，然后把其左右节点放入队列中；但是这个题要求要一层一层的读出来*/

 /*方法一：很笨，设置了一个临时队列，把这一层读出来的节点全部在放进去，然后再依次出队向队列中添加左右节点*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            queue<TreeNode*> tq;
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node -> val);
                if(node -> left) tq.push(node -> left);
                if(node -> right) tq.push(node -> right);
            }
            while(!tq.empty()){
                q.push(tq.front());
                tq.pop();
            }
            res.push_back(temp);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();//没有必要设置临时队列，只需要记录当前队列中的元素个数，只对队列中前n个元素操作就行了，与后面入队的元素无关
            vector<int> temp;
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node -> val);
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            res.push_back(temp);
        }
        return res;
    }
};