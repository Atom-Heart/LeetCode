/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy1 = new ListNode();
        ListNode *dummy2 = new ListNode();
        ListNode *ptr1 = dummy1, *ptr2 = dummy2;
        while(head != nullptr){
            if(head -> val < x){
                ListNode *node = head;
                head = head -> next;
                node -> next = nullptr;

                ptr1 -> next = node;
                ptr1 = ptr1 -> next;
            }
            else{
                ListNode *node = head;
                head = head -> next;
                node -> next = nullptr;
                
                ptr2 -> next = node;
                ptr2 = ptr2 -> next;
            }
        }
        ptr1 -> next = dummy2 -> next;
        return dummy1 -> next;
    }
};