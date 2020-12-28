/*堆*/
class Solution {
public:
    struct cmp{
        bool operator()(ListNode *l1, ListNode *l2){
            return l1 -> val > l2 -> val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        auto dummy = new ListNode(-1);
        ListNode *tail = dummy;
        for(auto l : lists){
            if(l) pq.push(l);
        }

        while(!pq.empty()){
            ListNode* node = pq.top();
            tail -> next = node;
            pq.pop();
            if(node -> next)
                pq.push(node -> next);
            tail = tail -> next;
        }
        return dummy -> next;
    }
};

/*归并*/
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
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1, *head2 = l2;
        ListNode* dummy = new ListNode();
        ListNode* ptr = dummy;
        while(l1 && l2){
            if(l1 -> val > l2 -> val){
                ptr -> next = new ListNode(l2 -> val);
                l2 = l2 -> next;
            }
            else{
                ptr -> next = new ListNode(l1 -> val);
                l1 = l1 -> next;
            }
            ptr = ptr -> next;
        }
        while(l1){
            ptr -> next = new ListNode(l1 -> val);
            ptr = ptr -> next;
            l1 = l1 -> next;
        }
        while(l2){
            ptr -> next = new ListNode(l2 -> val);
            ptr = ptr -> next;
            l2 = l2 -> next;
        }
        return dummy -> next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        else if(lists.size() == 1) return lists[0];
        else if(lists.size() == 2) return mergeTwoLists(lists[0], lists[1]);
        int n = lists.size();
        int mid = n / 2;
        vector<ListNode*> left = vector(lists.begin(), lists.begin() + mid);
        vector<ListNode*> right = vector(lists.begin() + mid, lists.end());
        
        ListNode *l1 = mergeKLists(left);
        ListNode *l2 = mergeKLists(right);
        return mergeTwoLists(l1, l2);
    }
};
