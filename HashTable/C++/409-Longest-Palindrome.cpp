class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hash;
        for(char ch : s){
            hash[ch]++;
        }

        int ans = 0;
        /*每个字母可以拿出(v / 2)对，也就是(v / 2) * 2个*/
        for(auto [k, v] : hash){
            ans += (v / 2) * 2;
        }
        /*如果还有剩余，中间再放一个*/
        return ans < s.size() ? ans + 1 : ans;
    }
};