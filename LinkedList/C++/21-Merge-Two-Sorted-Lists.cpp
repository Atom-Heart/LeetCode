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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1, *head2 = l2;
        ListNode* dummy = new ListNode();
        ListNode* ptr = dummy;
        while(l1 && l2){
            if(l1 -> val > l2 -> val){
                ptr -> next = new ListNode(l2 -> val);
                l2 = l2 -> next;
            }
            else{
                ptr -> next = new ListNode(l1 -> val);
                l1 = l1 -> next;
            }
            ptr = ptr -> next;
        }
        while(l1){
            ptr -> next = new ListNode(l1 -> val);
            ptr = ptr -> next;
            l1 = l1 -> next;
        }
        while(l2){
            ptr -> next = new ListNode(l2 -> val);
            ptr = ptr -> next;
            l2 = l2 -> next;
        }
        return dummy -> next;
    }
};