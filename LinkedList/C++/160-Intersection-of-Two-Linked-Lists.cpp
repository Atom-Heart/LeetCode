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
    int length(ListNode *head){
        int len = 0;
        while(head){
            len++;
            head = head -> next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        int len1 = length(headA), len2 = length(headB);
        if(len1 > len2){
            int steps = len1 - len2;
            while(headA != nullptr && steps--){
                headA = headA -> next;
            }
        }
        else{
            int steps = len2 - len1;
            while(headB != nullptr && steps--){
                headB = headB -> next;
            }
        }

        while(headA != nullptr){
            if(headA == headB) return headA;
            headA = headA -> next;
            headB = headB -> next;
        }
        return nullptr;
    }
};