class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> hash;
        for(char ch : t) hash[ch]++;
        for(char ch : s){
            hash[ch]--;
        }

        for(auto [k, v] : hash){
            if(v > 0) return k;
        }
        return '*';
    }
};