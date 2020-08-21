/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*遍历树的每一个节点，算出当前节点左子树的深度和右子树的深度，如果高度差的绝对值小于二，则返回true*/
 /*自顶向下的思想，容易想到，但会产生很多重复计算*/
 
 /******************方法一（写的low）**************************************************/
class Solution {
public:
    bool flag = true;
    int depth(TreeNode* node){
        if(node == NULL) return 0;
        int left = depth(node -> left) + 1;
        int right = depth(node -> right) + 1;
        return max(left, right);
    }
    void DFS(TreeNode* node){//先序遍历
        if(node == NULL) return;
        int left = depth(node -> left);//计算左子树深度
        int right = depth(node -> right);//计算右子树深度
        if(abs(left - right) >= 2) {
            flag = false;
            return;
        }
        DFS(node -> left);
        if(flag == false) return;//如果某个节点已经不符合定义，无需再向下遍历
        DFS(node -> right);
    }
    bool isBalanced(TreeNode* root) {
        DFS(root);
        return flag;
    }
};



/************************方法二（和方法一思想一样，但优化了dfs的过程）**********************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*遍历树的每一个节点，算出当前节点左子树的深度和右子树的深度，如果高度差的绝对值小于二，则返回true*/
class Solution {
public:
    int depth(TreeNode* node){
        if(node == NULL) return 0;
        int left = depth(node -> left) + 1;
        int right = depth(node -> right) + 1;
        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return abs(depth(root -> left) - depth(root -> right)) <= 1 && isBalanced(root -> left) && isBalanced            (root -> right);
    }
};

/*****************方法三：从底至顶（提前阻断）******************************/
/*思路是对二叉树先做先序遍历，从底至顶返回子树的最大高度，若判定某子树不是平衡树则“减枝”，直接向上返回*/
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
    int depth(TreeNode* node){
        if(node == nullptr) return 0;
        int left = depth(node -> left);
        if(left == -1) return -1;
        int right = depth(node -> right);
        if(right == -1) return -1;
        if(abs(left - right) < 2) return max(left, right) + 1;
        else return -1;
    }
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
};