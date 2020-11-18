/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*现在取第到k个数的概率：取第k个数:1/k,不取第k+1,k+2,````N个数 ------> 1/k * k/k+1 * k+1/k+2 * ```````` N-1/N，消元得到1/N，取到每个数的概率都是1/N */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        node = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ans = -1, count = 0;
        ListNode* node_ = node;
        while(node_){
            count++;
            /*当count == 1时，取余为0的概率为1；当count == 2时，取余为0的概率为1/2;当count == 3时，取余为0的概率为1/3;`````````*/
            if(rand() % count == 0){
                ans = node_ -> val;
            }
            node_ = node_ -> next;
        }
        return ans;
    }
    ListNode* node;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */