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
	/*反转left到right的链表*/
	ListNode* reverseList(ListNode* left, ListNode* right) {
		if (left == right) {
			return left;
		}
		ListNode *ret = reverseList(left->next, right);
		left->next->next = left;
		left->next = nullptr;
		return ret;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 0 || head == nullptr || head->next == nullptr) return head;
		/*得到第一次待翻转的左右指针*/
		ListNode *left = head;
		ListNode *right = head;
		int step = k;
		while (step - 1 != 0) {
			if (right->next != nullptr) {
				right = right->next;
			}
			else {
				return head;
			}
			step--;
		}
		/*得到翻转后链表的头节点*/
		ListNode *ans = right;
		/*得到上一次反转的尾节点*/
		ListNode *pre = left;
		/*标记什么时候开始首位连接,false表示不连接*/
		bool flag = false;
		bool end = false;

		while (right != nullptr && left != nullptr && end == false) {
			ListNode *next = right->next;//待翻转链表的最后一个位置的下一个位置
			ListNode *node = reverseList(left, right);
			/*更新左右指针*/
			right = left;
			left = node;
			right->next = next;//这时right -> next == nullptr
			/*连接之前的反转结果*/
			if (flag) {
				pre->next = left;
				pre = right;//更新pre
			}
			else {
				flag = true;
			}
			/*更新左右指针指向下一个待翻转的链表段*/

			/*左指针更新完毕*/
			if (right->next == nullptr) {
				break;
			}
			else {
				left = right->next;
			}
			/*更新右指针*/
			step = k;
			while (step != 0) {
				if (right->next == nullptr) {
					end = true;
					break;
				}
				else {
					right = right->next;
				}
				step--;
			}
		}
		return ans;
	}
};