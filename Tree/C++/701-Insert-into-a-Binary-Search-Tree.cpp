/*方法一：递归*/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            root = new TreeNode(val);
            return root;
        }

        if(root -> val < val) root -> right = insertIntoBST(root -> right, val);
        else root -> left = insertIntoBST(root -> left, val);

        return root;
    }
};

/*方法二：迭代*/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        TreeNode* ptr = root;

        while(1){
            if(ptr -> val < val){
                if(ptr -> right == nullptr){
                    ptr -> right = new TreeNode(val);
                    break;
                }
                else{
                    ptr = ptr -> right;
                }
            }
            else{
                if(ptr -> left == nullptr){
                    ptr -> left = new TreeNode(val);
                    break;
                }
                else{
                    ptr = ptr -> left;
                }
            }
        }
        return root;
    }
};