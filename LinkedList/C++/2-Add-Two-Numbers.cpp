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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        while(l1 || l2){
            int num1 = l1 ? l1 -> val : 0;
            int num2 = l2 ? l2 -> val : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            cur -> next = node;
            cur = node;
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
        }
        if(carry) cur -> next = new ListNode(1);
        return head -> next;
    }
};