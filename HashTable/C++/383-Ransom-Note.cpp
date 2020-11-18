class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> words(26, 0);
        for(char ch : magazine) words[ch - 'a'] += 1;

        for(char ch : ransomNote){
            words[ch - 'a'] -= 1;
            if(words[ch - 'a'] < 0) return false;
        }
        return true;
    }
};