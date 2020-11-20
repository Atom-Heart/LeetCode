/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr) return nullptr;
        Node* cur = head;
        while(cur != nullptr){
            if(cur -> child == nullptr) cur = cur -> next;
            else{
                Node *next = cur -> next;
                Node *child = flatten(cur -> child);
                cur -> next = child;
                child -> prev = cur;
                cur -> child = nullptr;
                if(next != nullptr){
                    while(cur -> next != nullptr){
                        cur = cur -> next;
                    }
                    cur -> next = next;
                    next -> prev = cur;
                    cur = cur -> next;
                }
            } 
        }
        return head;
    }
};