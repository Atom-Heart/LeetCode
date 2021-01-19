class Solution {
public:
    unordered_set<string> st;
    vector<string> ans;
    /*dp[i]表示 i~n-1是否能拆分成字典里的单词*/
    vector<bool> dp;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string word : wordDict) st.insert(word);
        int n = s.size();
        /*这里要将大小多设置一位的原因是避免边界问题，在dfs中使用了dp[i + 1]*/
        dp.resize(n + 1, false);
        dp[n] = true;

        /*从后向前遍历*/
        for(int i = n - 1; i >= 0; i--){
            if(st.count(s.substr(i, n - i))){
                dp[i] = true;
                continue;
            }

            for(int j = i + 1; j < n ; j++){
                if(dp[j] == true && st.count(s.substr(i, j - i))){
                    dp[i] = true;
                    break;
                }
            }
        }

        vector<string> route;
        dfs(s, route, 0);
        return ans;
    }

    void dfs(string s, vector<string>& route, int begin){
        if(begin >= s.size()){
            string str;
            for(auto s : route){
                str += s;
                str += " ";
            }
            str.pop_back();//去掉末尾多余空格
            ans.push_back(str);
            return;
        }

        for(int i = begin; i < s.size(); i++){
            string word = s.substr(begin, i - begin + 1);
            /*利用dp[i + 1]剪枝*/
            if(st.count(word) && dp[i + 1]){
                route.push_back(word);
                dfs(s, route, i + 1);
                route.pop_back();
            }
        }
    }
};