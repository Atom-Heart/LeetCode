/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*递归*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode *next = head -> next;
        
        if(head -> val == next -> val){
            while(next != nullptr && head -> val == next -> val){//移动到下一个不重复的元素
                next = next -> next;
            }
            head = deleteDuplicates(next);
        }
        else{
            head -> next = deleteDuplicates(next);
        }
        return head;
        
    }
};

/*迭代*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode *node = new ListNode(0);
        node -> next = head;
        head = node;
        ListNode *left, *right;
        while(node -> next != nullptr){
            left = node -> next;
            right = left;
            while(right -> next != nullptr && right -> next -> val == left -> val){
                right = right -> next;
            }
            if(right == left) node = node -> next;
            else node -> next = right -> next;
        }
        return head -> next;
        
    }
};