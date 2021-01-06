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
    ListNode *next = nullptr, *tail = nullptr;
    ListNode *reverse(ListNode *head, int steps){
        if(head == nullptr || head -> next == nullptr) return head;
        if(steps == 0){
            next = head -> next;
            return head;
        }
        ListNode *node = reverse(head -> next, steps - 1);
        head -> next -> next = head;
        head -> next = nullptr;
        return node;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode *dummy = new ListNode();
        dummy -> next = head;

        ListNode *ptr = dummy;
        ListNode *pre = nullptr;
        int k = m;
        while(k--){
            pre = ptr;
            ptr = ptr -> next;
        }
        pre -> next = reverse(ptr, n - m);
        ptr -> next = next;
        return dummy -> next;
    }
};