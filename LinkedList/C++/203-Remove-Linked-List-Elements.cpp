/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*方法一：迭代*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* cur = dummy;
        while(cur != nullptr && cur -> next != nullptr){
            if(cur -> next -> val == val){
                ListNode* temp = cur -> next;
                while(temp -> next != nullptr && temp -> next -> val == val){//处理多个连续待删除节点
                    temp = temp -> next;
                }
                cur -> next = temp -> next;
                if(cur == dummy) {//处理待删除节点是链首元素
                    continue;
                }
            }
            cur = cur -> next;
        }
        return dummy -> next;
    }
};


/*方法二：递归，太巧妙了*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        head -> next = removeElements(head -> next, val);
        return head -> val == val ? head -> next : head;
    }
};