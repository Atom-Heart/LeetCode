/*方法一：回溯*/
class Solution {
public:
	vector<string> res;
	vector<string> removeInvalidParentheses(string s) {
		int left = 0, right = 0;//保存s中左右括号多余的个数
		/*统计出了左右括号多余的个数,)(这种情况也能判断*/
		for (auto ch : s) {
			if (ch == '(') {//记录左括号的个数
				left++;
			}
			else if(ch == ')') {
				if (left > 0) {//左括号还有没有抵消的
					left--;//抵消
				}
				else {//左括号已经被抵消完了
					right++;//增加右括号个数
				}
			}
		}
		DFS(s, 0, left, right);
		return res;
	}
	/*
	*  @param s: 源字符串
	*  @param st:遍历字符串的起始位置
	*  @param left：多余的左括号个数
	*  @param right:多余的右括号个数
	*/
	void DFS(string s, int st, int left, int right) {
		if (left == 0 && right == 0) {
			if (check(s)) {
				res.push_back(s);
			}
			return;
		}

		for (int i = st; i < s.size(); i++) {
			if (left > 0 && s[i] == '(') {
				if (i > 0 && s[i] == s[i - 1]) continue;//去重,比如：())，删除第一个或第二个右括号，结果不变
				DFS(s.substr(0, i) + s.substr(i + 1, s.size() - i - 1), i, left - 1, right);//去除多于括号后的字符串，继续进行递归删除
			}
			if (right > 0 && s[i] == ')') {
				if (i > 0 && s[i] == s[i - 1]) continue;
				DFS(s.substr(0, i) + s.substr(i + 1, s.size() - i - 1), i, left, right - 1);
			}
		}

	}

	bool check(string s) {
		stack<char> st;
		for (auto ch : s) {
			if (ch == '(') {
				st.push(ch);
			}
			else if (ch == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
				}
				else {
					return false;
				}
			}
		}
		return st.empty();
	}

};