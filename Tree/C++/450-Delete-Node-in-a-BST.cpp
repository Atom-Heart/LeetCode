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
    TreeNode* deleteNode(TreeNode* root, int key) {
        del(root, key);
        return root;
    }
    void del(TreeNode* &root, int key){
        if(root == nullptr) return;
        if(root -> val == key){//找到要删除的节点了
            if(root -> left == nullptr && root -> right == nullptr){//待删除结点是叶子节点
                root = nullptr;
            }
            else if(root -> right == nullptr){//左子树不空 /*这个判空的条件很妙*/
                root = root -> left;
            }
            else if(root -> left == nullptr){//右子树不空
                root = root -> right;
            }
            else{//左右子树都不空
                /*1.先找到root的后继(先序遍历)*/
                TreeNode* node = root -> right;
                while(node -> left != nullptr) node = node -> left;

                /*2.将后继的值覆盖到root上,然后将后继删除*/
                root -> val = node -> val;
                del(root -> right, node -> val);
            }
        }
        else if(root -> val > key){
            del(root -> left, key);
        }
        else{
            del(root -> right, key);
        }
    }
};