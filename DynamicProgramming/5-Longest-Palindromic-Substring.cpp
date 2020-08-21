/*回文数天然的有着状态转移的性质，一个字符串是不是回文串，取决于最边缘的两个数是否相等和剩下的字串是不是回文串*/


class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int n = s.size();//字符串的长度
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        /*dp[i][j]表示范围是i~j的字串是不是回文串*/
        /*dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]) ? true : false*/
        /*由于当前状态取决于左斜下方的状态，所以要注意遍历的顺序,对角线的元素必为true*/
        int start = 0;//表示字串的起始位置
        int max_len = 1;//表示字串的长度
        for(int j = 1; j < n; j++){
            for(int i = 0; i < j; i++){
                if(s[i] != s[j]){//如果第一个和最后一个字符不相等，那么肯定不是回文串
                    dp[i][j] = false;
                }
                else{
                    if(j - i < 3){
                        dp[i][j] = true;        
                    }
                    else{
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    
                    if(dp[i][j] && j - i + 1 > max_len){
                        max_len = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, max_len);
    }
};