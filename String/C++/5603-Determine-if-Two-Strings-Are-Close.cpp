/*这道题在周赛的时候其实快想出来了。这道题返回的只是true和false，不用去考虑字符的具体变化过程，所以这道题需要根据两个条件直接去判断就可以了*/
/*操作一：只要两个字符串出现的字母是一样的，就可以转换*/
/*操作二：在条件一的基础上，只要两个字符串出现单词的频率（单词不一样无所谓，只要求出现频次一样）能匹配上就可以*/
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> a(26, 0);
        vector<int> b(26, 0);
        for(char ch : word1) a[ch - 'a'] += 1;
        for(char ch : word2) b[ch - 'a'] += 1;

        for(int i = 0; i < 26; i++) 
            if((a[i] > 0) - (b[i] > 0) != 0) return false;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for(int i = 0; i < 26; i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};