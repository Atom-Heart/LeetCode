class Solution {
public:
    string reverseWords(string s) {
        string ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;//跳过前导空格
            else{
                int j = i;
                while(j < s.size() && s[j] != ' '){//找到单词结束的位置
                    j++;
                }
                string word = s.substr(i, j - i);//获得单词
                word += ' ';
                ans.insert(0, word);
                i = j;
            }
        }
        return ans.substr(0, ans.size() - 1);
    }
};