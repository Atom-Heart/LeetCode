class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.size();
		vector<int> dp(n, 0);
		for (int i = 1; i < n; i++) {
			if (s[i] == '(') {
				dp[i] = 0;
			}
			else {
				if (s[i - 1] == '(') {
					if (i - 2 >= 0) {
						dp[i] = dp[i - 2] + 2;
					}
					else {
						dp[i] += 2;
					}

				}
				else if (s[i - 1] == ')') {
					if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') { //i - dp[i - 1]的意义就是向前移动i - 1个位置,举个例子：(()())，当i = 5时，dp[i - 1]保存了以s[i - 1]为结尾的字串的长度
																				 //i - dp[i - 1]的结果就是这个以s[i - 1]结尾长度为dp[i - 1]的字串的第一个字符的下标
																				 //当i从0开始计数时，i - n代表[i - n, i)这个字串的范围，i - n + 1代表剩余字串的总长度
						dp[i] = dp[i - 1] + 2;
						if (i - dp[i - 1] - 2 >= 0) {
							dp[i] += dp[i - dp[i - 1] - 2];
						}
					}
				}
			}
		}
		int res = 0;
		for (int i = 0; i < dp.size(); i++) {
			if (dp[i] > res) res = dp[i];
		}
		return res;
	}
};

https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-powcai/