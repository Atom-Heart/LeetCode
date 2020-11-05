 /*方法一：分治*/
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == nullptr) return ans;
        vector<string> res1 = binaryTreePaths(root -> left);
        vector<string> res2 = binaryTreePaths(root -> right);
        if(res1.size() == 0 && res2.size() == 0) {
            ans.push_back(to_string(root -> val));
            return ans;
        }
        for(auto str1 : res1){
            string temp = to_string(root -> val) + "->";
            temp += str1;
            ans.push_back(temp);
        }
        for(auto str2 : res2){
            string temp = to_string(root -> val) + "->";
            temp += str2;
            ans.push_back(temp);
        }
        return ans;
    }
};

/*方法二：DFS*/
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == nullptr) return ans;

        binaryTreePaths(root, ans, "");
        return ans;
    }
    void binaryTreePaths(TreeNode* root, vector<string>& res, string path){
        path += to_string(root -> val);
        if(root -> left == nullptr && root -> right == nullptr){
            res.push_back(path);
            return;
        }
        if(root -> left) binaryTreePaths(root -> left, res, path + "->");
        if(root -> right) binaryTreePaths(root -> right, res, path + "->");
    }
};