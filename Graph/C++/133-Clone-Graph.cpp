/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
/*方法一：BFS*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        unordered_map<Node*, Node*> mp;//用来标记是否被访问过
        stack<Node*> st;
        st.push(node);
        mp[node] = new Node(node -> val);

        while(!st.empty()){
            Node *cur = st.top();
            st.pop();
            for(auto temp : cur -> neighbors){
                if(mp.find(temp) == mp.end()){//如果这个节点没有被访问过
                    mp[temp] = new Node(temp -> val);//建立映射
                    st.push(temp);//加入到接下来需要遍历的栈中
                }
                mp[cur] -> neighbors.push_back(mp[temp]);
            }
        }
        return mp[node];
    }
};

/*方法二：DFS*/
class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        if(mp.count(node)) return mp[node];//已经被访问过，直接返回
        auto new_root = new Node(node -> val);
        mp[node] = new_root;
        for(auto temp : node -> neighbors){
            mp[node] -> neighbors.push_back(cloneGraph(temp));
        }
        return mp[node];
    }
};