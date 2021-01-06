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
    ListNode* reverse(ListNode *head){
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode* node = reverse(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return node;
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return true;
        ListNode *slow = head, *fast = head;
        while(fast != nullptr){
            slow = slow -> next;
            fast = fast -> next;
            if(fast != nullptr) fast = fast -> next;
        }
        ListNode *newHead = reverse(slow);
        
        while(head != nullptr && newHead != nullptr){
            if(head -> val != newHead -> val) return false;
            head = head -> next;
            newHead = newHead -> next;
        }
        return true;
    }
};