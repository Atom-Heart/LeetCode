class MyLinkedList {
public:
    struct ListNode{
        ListNode* next;
        int val;
        ListNode(int num){
            next = nullptr;
            val = num;
        }
    };

    /** Initialize your data structure here. */
    MyLinkedList() {
        dummy = new ListNode(-1);
        tail = dummy;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        index += 1;
        ListNode* cur = dummy;
        while(cur != nullptr && index--){
            cur = cur -> next;
        }
        return cur == nullptr ? -1 : cur -> val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* ptr = new ListNode(val);
        ptr -> next = dummy -> next;
        dummy -> next = ptr;
        if(tail == dummy) tail = ptr;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        tail -> next = new ListNode(val);
        tail = tail -> next;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode* ptr = dummy;
        while(ptr != nullptr && index--){
            ptr = ptr -> next;
        }
        
        ListNode* temp = new ListNode(val);
        if(ptr == tail){
            tail = temp;
        }
        temp -> next = ptr -> next;
        ptr -> next = temp;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode* ptr = dummy;
        while(ptr != nullptr && index--){
            ptr = ptr -> next;
        }
        if(tail == ptr -> next){
            tail = ptr;
        }
        if(ptr -> next != nullptr){
            ptr -> next = ptr -> next -> next;
        }
    }
private:
    ListNode* dummy;
    ListNode* tail;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

 /*
 ["MyLinkedList"
 ,"addAtHead",  7
 "addAtHead",   2
 "addAtHead",   1
 "addAtIndex",  3 0
 "deleteAtIndex",   2
 "addAtHead",   6
 "addAtTail",   4
 "get",         4
 "addAtHead",   4
 "addAtIndex",  5 0
 "addAtHead"]   6
[[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
 */