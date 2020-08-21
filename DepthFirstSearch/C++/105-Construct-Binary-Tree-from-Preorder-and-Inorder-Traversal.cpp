/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
     * 使用数组 preorder 在索引区间 [preLeft, preRight] 中的所有元素
     * 和数组 inorder 在索引区间 [inLeft, inRight] 中的所有元素构造二叉树
     *
     * @param preorder 二叉树前序遍历结果
     * @param preLeft  二叉树前序遍历结果的左边界
     * @param preRight 二叉树前序遍历结果的右边界
     * @param inorder  二叉树后序遍历结果
     * @param inLeft   二叉树后序遍历结果的左边界
     * @param inRight  二叉树后序遍历结果的右边界
     * @return 二叉树的根结点
     */

/*作者：liweiwei1419
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/qian-xu-bian-li-python-dai-ma-java-dai-ma-by-liwei/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/


/*核心思想：先序遍历的第一个节点是树的根节点*/
/*在中序遍历中找到根节点的位置，那么以这个位置为轴，可以把中序遍历的结果分成两个部分，左边是左子树，右边
是右子树，并且可以得到左子树和右子树的序列长度，通过这个长度计算先序遍历左右子树的边界位置，然后进行递归
完成树的构造*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft
    , int inRight){
        if(preLeft > preRight || inLeft > inRight){//递归边界，思考为什么边界会这样写
            return NULL;
        }
        int pivot = preorder[preLeft];//在先序中获得根节点的值
        TreeNode *root = new TreeNode(pivot);
        int pivotIndex = inLeft;
        while(inorder[pivotIndex] != pivot){//得到在中序中根节点的下标
            pivotIndex++;
        }
        root -> left = buildTree(preorder, preLeft + 1, pivotIndex - inLeft + preLeft, inorder, inLeft,
        pivotIndex - 1);//递归完成后续操作
        root -> right = buildTree(preorder, pivotIndex - inLeft + preLeft + 1, preRight, inorder,                  pivotIndex + 1, inRight);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preRight = preorder.size() - 1;
        int inRight = inorder.size() - 1;
        return buildTree(preorder, 0, preRight, inorder, 0, inRight);
    }
};