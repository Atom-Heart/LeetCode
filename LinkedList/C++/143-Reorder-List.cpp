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
 /*方法一：暴力，因为每次寻找tail都需要去遍历*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        int len = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            len++;
            temp = temp -> next;
        }
        int step = len - 1;
        ListNode* pre = nullptr;
        ListNode* new_head = head;
        ListNode* tail = nullptr;
        bool flag = false;
        while(step >= 0){
            /*将前驱节点和当前头节点连接起来，但第一次不用连接*/
            if(flag && pre != nullptr){
                pre -> next = head;
            }
            /*获取尾节点*/
            int temp_step = step;
            tail = head;
            while(tail != nullptr && temp_step--){
                tail = tail -> next;
            }
            /*获取下一次迭代的头节点*/
            if(head != nullptr) new_head = head -> next;
            /*获取下一次迭代的前驱节点*/
            pre = tail;
            /*连接首尾节点*/
            if(head != nullptr) head -> next = tail;
            /*更新首节点*/
            head = new_head;
            /*更新标志位*/
            flag = true;
            step -= 2;
        }
        pre -> next = nullptr;
    }
};

 /*方法二：存储，由于链表是链式结构无法随机存取，所以我就把他每个节点都保存在顺序容器中*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        vector<ListNode*> vec;
        ListNode* temp = head;
        while(temp){
            vec.push_back(temp);
            temp = temp -> next;
        }

        int left = 0;
        int right = vec.size() - 1;
        int pre = right;

        while(left < right){
            vec[left] -> next = vec[right];
            left++;
            if(left == right){//可能会提前相遇
                break;
            }
            vec[right] -> next = vec[left];//这种写法很巧妙，就不用设置前驱节点了
            right--;
        }
        vec[left] -> next = nullptr;//最后一个节点的后继节点要置空
    }
};

/*方法三：递归*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return;
        }
        ListNode* pre_tail = head;
        while(pre_tail -> next -> next != nullptr){
            pre_tail = pre_tail -> next;
        }
        ListNode* tail = pre_tail -> next;
        pre_tail -> next = nullptr;
        tail -> next = head -> next;
        head -> next = tail;
        reorderList(tail -> next);
    }
};

 /*方法四：利用一头一尾取元素的特性*/
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head -> next == nullptr){
            return head;
        }
        ListNode* new_head = reverse(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return new_head;
    }
    void reorderList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr || head -> next -> next == nullptr) return;
        ListNode *slow = head, *fast = head;
        while(fast -> next != nullptr && fast -> next -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* new_head = slow -> next;
        slow -> next = nullptr;

        new_head = reverse(new_head);

        while(new_head != nullptr && head != nullptr){
            ListNode* temp1 = head -> next;
            head -> next = new_head;
            ListNode* temp2 = new_head -> next;
            new_head -> next = temp1;
            head = temp1;
            new_head = temp2;
        }
    }
};