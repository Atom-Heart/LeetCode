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

 /*注意：题目中说了只是两个节点被错误的交换！！！*/
 
 /*方法一：*/
class Solution {
public:
    vector<TreeNode*> vec;//保存中序遍历的结果
    void inOrder(TreeNode* root){
        if(root == nullptr) return;
        inOrder(root -> left);
        vec.push_back(root);
        inOrder(root -> right);
    }
    void recoverTree(TreeNode* root) {
        if(root == nullptr) return;
        inOrder(root);
        TreeNode *begin = nullptr, *end = nullptr;
        /*这个for循环是用来找到那两个需要交换的节点的，找到第一个逆序的对的时候，begin只在这时更改，其余次迭代如果遇到逆序，只需要去更改end，为什么这样做可以考虑输入示例1：这棵树中序遍历
        的结果是3 2 1，如果只是换了3和2的位置，那么结果明显不符。所以要继续向下寻找，将3和1互换*/
        for(int i = 0; i < vec.size() - 1; i++){
            if(vec[i] -> val > vec[i + 1] -> val){
                 end = vec[i + 1];
                 if(begin == nullptr){
                     begin = vec[i];
                 }
            }
        }

        int temp = begin -> val;
        begin -> val = end -> val;
        end -> val = temp;
    }
};