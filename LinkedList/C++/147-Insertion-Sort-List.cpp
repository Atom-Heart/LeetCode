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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode* dummy = new ListNode;
        dummy -> next = head;
        head = head -> next;
        dummy -> next -> next = nullptr;

        while(head != nullptr){
            ListNode* next = head -> next;
            ListNode* new_head = dummy;
            while(new_head -> next != nullptr){
                if(head -> val < new_head -> next -> val){
                    head -> next = new_head -> next;
                    new_head -> next = head;
                    break;
                }
                else{
                    new_head = new_head -> next;
                }
            }
            if(new_head -> next == nullptr){
                new_head -> next = head;
                head -> next = nullptr;
            }
            head = next;
        }
        return dummy -> next;
    }
};