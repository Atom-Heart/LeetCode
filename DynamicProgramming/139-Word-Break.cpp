/*动态规划算法，dp[i]表示s前i个字符能否拆分
        转移方程：dp[j] = dp[i] && check(s[i+1, j]);
        check(s[i+1, j])就是判断i+1到j这一段字符是否能够拆分
        其实，调整遍历顺序，这等价于s[i+1, j]是否是wordDict中的元素
        这个举个例子就很容易理解。
        假如wordDict=["apple", "pen", "code"],s = "applepencode";
        dp[8] = dp[5] + check("pen")
        翻译一下：前八位能否拆分取决于前五位能否拆分，加上五到八位是否属于字典
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len, false);//dp[i]代表s中[0, i]范围的字串是否在wordDict中出现
        
        unordered_set<string> wordSet;
        for(auto word : wordDict){//把字典中的单词放入set中
            wordSet.insert(word);
        }

        for(int i = 0; i < len; i++){
            if(wordSet.find(s.substr(0, i + 1)) != wordSet.end()){//如果s[0...i]在字典中出现过
                dp[i] = true;
                continue;//后面就不用判断了，这个单词在字典里本来就有，那意思就是“拆分成一个”
            }

            for(int j = 0; j < i; j++){//将s[0...i]拆分成两个部分 -> s[0...j] && s[j + 1 ... i]
                if(dp[j] == true && wordSet.find(s.substr(j + 1, i - j)) != wordSet.end()){
                    dp[i] = true;
                    break;//一旦拆分成功，立刻返回
                }
            }       
        }
        return dp[len - 1];
    }
};