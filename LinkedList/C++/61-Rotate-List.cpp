/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0) return head;
        ListNode *ptr = head;
        int len = 0;
        while(ptr != nullptr){
            len++;
            ptr = ptr -> next;
        }
        ListNode *dummy = new ListNode();
        dummy -> next = head;
        
        k = len - (k % len);
        if(k == 0 || k == len) return head;
        ListNode *newHead = nullptr, *tail = nullptr, *pre = dummy;
        while(pre != nullptr && k--) pre = pre -> next;
        newHead = pre -> next;

        dummy -> next = newHead;

        pre -> next = nullptr;

        tail = newHead;

        while(tail != nullptr && tail -> next != nullptr) tail = tail -> next;
        if(tail) tail -> next = head;
        return dummy -> next;
        
        

    }
};