/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
/*我自己写的迭代，时间复杂度O(N)，不符合要求*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        root -> next = nullptr;
        vector<Node*> vec;
        vec.push_back(root);
        while(!vec.empty()){
            for(int i = 0; i < vec.size() - 1; i++){
                vec[i] -> next = vec[i + 1];
            }
            int size = vec.size();
            while(size--){
                Node *temp = vec.front();
                vec.erase(vec.begin());
                if(temp -> left != nullptr) vec.push_back(temp -> left);
                if(temp -> right != nullptr) vec.push_back(temp -> right);
            }
        }
        return root;
    }
};

/*时间复杂度为O(N)的迭代*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        Node *ptr = root;
        while(root -> left){
            for(auto p = root; p; p = p -> next){
                p -> left -> next = p -> right;
                if(p -> next){
                    p -> right -> next = p -> next -> left;
                }
            }
            root = root -> left;
        }
        return ptr;
    }
};

/*递归写法*/
class Solution {
public:
    void dfs(Node *root){
        if(root == nullptr){
            return;
        }
        Node *left = root -> left;
        Node *right = root -> right;

        while(left != nullptr){
            left -> next = right;
            left = left -> right;
            right = right -> left;
        }
        dfs(root -> left);
        dfs(root -> right);
    }
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
};