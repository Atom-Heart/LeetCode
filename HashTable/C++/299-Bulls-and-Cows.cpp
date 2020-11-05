class Solution {
public:
    string getHint(string secret, string guess) {
        string ans;
        unordered_map<char, int> mp;
        int count_A = 0, count_B = 0;
        /*做字母的映射*/
        for(int i = 0; i < secret.size(); i++){
            if(mp.find(secret[i]) == mp.end()){
                mp[secret[i]] = 1;
            }
            else{
                mp[secret[i]] += 1;
            }
        }

        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]){
                count_A++;
                mp[secret[i]] -= 1;//被完全匹配的情况访问过了
            }
        }
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] != guess[i] && mp.find(guess[i]) != mp.end() && mp[guess[i]] != 0){
                count_B++;
                mp[guess[i]]--;
            }
        }
        ans = ans + to_string(count_A) + "A" + to_string(count_B) + "B";
        return ans;

    }
};