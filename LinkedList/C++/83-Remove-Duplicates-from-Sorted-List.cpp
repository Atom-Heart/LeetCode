/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*我自己的迭代写法*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode *node = head;

        while(node != nullptr && node -> next != nullptr){
            if(node -> next -> val == node -> val){
               ListNode *temp = node -> next;
               while(temp != nullptr){
                   if(temp -> val == node -> val){
                       temp = temp -> next;
                   } 
                   else{
                        break;
                   }
               }
               node -> next = temp;
               node = temp;
            }
            else{
                node = node -> next;
            }
        }
        return head;
    }
};
