/*做这道题的时候一开始我想的是：暴力法，求出所有字串，然后统计这些字串中的字符数量，再求出最长字串。这种方法没有充分利用题中的条件去剪枝。那就应该去往剪枝的方向去考虑，该如何剪枝呢？
一般第一想法肯定会想到双指针，但我发现用快慢指针，左右指针，常规双指针，滑动窗口（能做，但很难想）都不能解决这个问题，因为我不知道怎么维护字串。关键点在于:先统计子串中所有字母出现的次数，出现次数小于k次的字母是一定不能选的，
所以这个字母是不会出现在最终的最长子串中，所以当前字串可以被这个字母分成两个更短的字串，在对两个字串进行递归处理*/

/*hash(统计字母出现次数) + 分治(问题的解决策略) + 双指针(维护当前字串)*/
class Solution {
public:

    int longestSubstring(string s, int k) {
        vector<int> hash(26, 0);
        for(char ch : s) hash[ch - 'a']++;
        /*统计出现次数小于k的字母的下标*/
        vector<int> split;
        for(int i = 0; i < s.size(); i++){
            if(hash[s[i] - 'a'] > 0 && hash[s[i] - 'a'] < k) split.push_back(i);
        }
        if(split.size() == 0) return s.size();
        /*加入右边界*/
        split.push_back(s.size());
        int left = 0, ans = 0;
        for(int i = 0; i < split.size(); i++){
            int len = split[i] - left;
            if(len > ans)//剪枝：字串的总长度应该大于ans才有意义
                ans = max(ans, longestSubstring(s.substr(left, len), k));
            left = split[i] + 1;    
        }
        return ans;
    }
};