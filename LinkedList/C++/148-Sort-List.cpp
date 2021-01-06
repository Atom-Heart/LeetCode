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
    /*bottom-to-up算法，直接从小规模开始合并*/
    ListNode* sortList(ListNode* head) {
        ListNode *dummy = new ListNode();
        dummy -> next = head;
        ListNode *ptr = head;
        int len = 0;

        while(ptr){
            len++;
            ptr = ptr -> next;
        }
        /*如果有8个数：2个一组， 4个一组， 8个一组*/
        for(int size = 1; size < len; size <<= 1){
            ListNode *cur = dummy -> next;
            ListNode *tail = dummy;//关键！用来连接子问题
            while(cur){
                ListNode *left = cur;
                ListNode *right = cut(cur, size);
                cur = cut(right, size);

                tail -> next = merge(left, right);
                while(tail -> next){
                    tail = tail -> next;
                }
            }
        }
        return dummy -> next;
    }

    ListNode* merge(ListNode *l1, ListNode *l2){
        ListNode *dummy = new ListNode();
        auto ptr = dummy;
        while(l1 && l2){
            if(l1 -> val < l2 -> val){
                ptr -> next = l1;
                ptr = l1;
                l1 = l1 -> next;
            }
            else{
                ptr -> next = l2;
                ptr = l2;
                l2 = l2 -> next;
            }
        }
        ptr -> next = l1 ? l1 : l2;
        return dummy -> next;
    }
    /*先当与链表的split操作，取从当前结点开始的n个结点（包括当前节点），然后断开*/
    ListNode* cut(ListNode *head, int n){
        ListNode *p = head;
        while(--n && p) p = p -> next;
        if(!p) return nullptr;
        
        ListNode *next = p -> next;
        p -> next = nullptr;
        return next;
    }
};