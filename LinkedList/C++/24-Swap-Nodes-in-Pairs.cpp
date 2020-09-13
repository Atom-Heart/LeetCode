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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        ListNode *L = head;
        ListNode *R = head -> next;
        ListNode *P = head -> next;
        ListNode *ans = R;
        int flag = 0;//第一次反转时没有必要连接上一个部分
        while(L != nullptr && R != nullptr){
            /*反转节点*/
            L -> next = R -> next;
            R -> next = L;
            /*反转左右指针*/
            ListNode *node = L;
            L = R;
            R = node;
            /*连接上一个部分*/
            if(flag != 0){
                P -> next = L;
            }
            /*记录交换后的未节点*/
            P = R;
            /*移动左右指针*/
            if(R -> next != nullptr){
                L = R -> next;
            }
            else{
                break;
            }
            R = L -> next;\
            flag++;
        }
        return ans;
    }
};