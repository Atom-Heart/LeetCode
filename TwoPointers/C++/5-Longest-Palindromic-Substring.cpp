class Solution {
public:
/*双指针中心扩张法：如果回文子串的长度为奇数，那么该串有中心位置，就从该中心位置向外扩张；如果回文子串的长度
为偶数，那么中心位置就位于两个数中间*/
    string stringSpread(string s, int left, int right){//这种写法综合了回文子串是奇数或偶数的两种写法
        while(left >= 0 && right < s.size() && s[left] == s[right]){//如果左右相等那么就扩张
            left--;
            right++;
        }
        /*循环退出时必有s[left] != s[right],所以回文字串的起始位置在left + 1, 长度为right - left + 1 - 2
        减去的那个2就代表s[left]和s[right]，这两个不相等不能算进去*/
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s) {
        if(s.size() == 0 || s.size() == 1) return s;
        string res;
        for(int i = 0; i < s.size() - 1; i++){
            string temp = stringSpread(s, i, i);
            if(temp.size() > res.size()) res = temp;
            temp = stringSpread(s, i, i + 1);
            if(temp.size() > res.size()) res = temp;
        }
        return res;
    }
};