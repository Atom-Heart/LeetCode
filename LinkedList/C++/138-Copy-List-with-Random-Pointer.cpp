/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        unordered_map<Node*, int> mp1;
        unordered_map<Node*, int> mp2;

        Node *ptr = head;
        int idx = 0;
        while(ptr){
            mp2[ptr] = idx++;
            ptr = ptr -> next;
        }

        vector<Node*> vec;
        while(head){
            Node *cur = new Node(head -> val);
            vec.push_back(cur);

            if(head -> random == nullptr) mp1[cur] = -1;
            else mp1[cur] = mp2[head -> random];

            head = head -> next;
        }

        for(int i = 0; i < vec.size(); i++){
            if(i < vec.size() - 1){
                vec[i] -> next = vec[i + 1];
            }

            if(mp1[vec[i]] == -1){
                vec[i] -> random = nullptr;
            }
            else{
                vec[i] -> random = vec[mp1[vec[i]]];
            }
        }
        return vec[0];
    }
};