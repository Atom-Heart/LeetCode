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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        else if(head -> next == nullptr){
            return new TreeNode(head -> val);
        }
        
        ListNode *ptr = head;
        int len = 0;
        while(ptr){
            len++;
            ptr = ptr -> next;
        }
        len /= 2;
        ListNode *mid = head;
        ListNode *pre = nullptr;
        while(mid != nullptr && len--){
            pre = mid;
            mid = mid -> next;
        }
        pre -> next = nullptr;
        ListNode *newHead = mid -> next;
        TreeNode *root = new TreeNode(mid -> val);
        root -> left = sortedListToBST(head);
        root -> right = sortedListToBST(newHead);
        return root;
    }
};