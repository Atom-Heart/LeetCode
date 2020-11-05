/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "X,";
        /*帮我去得到我左右子树的序列化结果，然后加到我身上*/
        string leftNode = serialize(root -> left);
        string rightNode = serialize(root -> right);
        return to_string(root -> val) + "," +leftNode + rightNode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        /*根据','将data分为多个string*/
        list<string> list = split(data, ',');
        TreeNode *res = buildTree(list);
        return res;
    }
    TreeNode* buildTree(list<string> &strList){
        /*得到首节点*/
		/*之所以使用lis而不使用vector，是因为需要频繁对首元素进行操作，用vector不方便删除首元素，但list在O(1)时间复杂度内就能删除*/
        string strtmp = strList.front();
        strList.pop_front();
        /*如果是'X',说明子树为Null*/
        if(strtmp == "X"){
            return nullptr;
        }
        /*如果是数字，说明这个节点可以作为根节点*/
        TreeNode* node = new TreeNode(atoi(&strtmp[0]));
        /*依次去构建子树*/
        node -> left = buildTree(strList);
        node -> right = buildTree(strList);
        return node;

    }
    /*字符串分割函数*/
    list<string> split(string& str, char c){
        list<string> res;
        int begin = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == c){
                res.push_back(str.substr(begin, i - begin));
                begin = i + 1;
            }
        }
        return res;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));