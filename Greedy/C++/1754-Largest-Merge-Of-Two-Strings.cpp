class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i = 0, j = 0;
        int m = word1.size(), n = word2.size();
        
        string ans;
        while(i < m && j < n){
            if(word1.substr(i) > word2.substr(j)){
                ans += word1[i++];
            }
            else{
                ans += word2[j++];
            }
        }

        if(i < m) ans += word1.substr(i);
        if(j < n) ans += word2.substr(j);
        return ans;
    }
};