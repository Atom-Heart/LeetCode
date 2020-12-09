class Solution {
public:
    static bool cmp(string &a, string &b){
        if(a.size() != b.size()) return a.size() > b.size();
        int n = a.size();
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]) return a < b;
        }
        return a == b;
    }
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), cmp);
        for(auto word : d){
            int j = 0;
            for(int i = 0; i < s.size(); i ++){
                if(s[i] == word[j]){
                    j++;
                    if(j == word.size()) return word;
                }
            }
        }
        return "";
    }
};