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
 /*快慢指针,可以先向后走n步构造出一个含有n + 1个结点的窗口，然后把这个窗口平移到链表尾部*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int steps = n;
        ListNode* fast = head, *slow = head;
        while(steps--) fast = fast -> next;
        /*移除首结点*/
        if(fast == nullptr) return head -> next;
        
        while(fast -> next){
            slow = slow -> next;
            fast = fast -> next;
        }
        if(slow -> next){
            slow -> next = slow -> next -> next;
        }
        return head;
    }
};