/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        int white = 0, gray = 1;
        stack<pair<int, Node*>> st;
        st.push(make_pair(white, root));
        while(!st.empty()){
            int color = st.top().first;
            Node* node = st.top().second;
            st.pop();
            if(node == nullptr) continue;
            if(color == white){
                for(int i = node -> children.size() - 1; i >= 0; i--){
                    st.push(make_pair(0, node -> children[i]));
                }
                st.push(make_pair(1, node));
            }
            else{
                ans.push_back(node -> val);
            }
        }
        return ans;
    }
};