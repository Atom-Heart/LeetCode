class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int len = s.size();
        if(len == 1){
            return mp[s[0]];
        }

        int index = 0;
        while(index < len){
            if(index == len - 1){
                ans += mp[s[index]];
                index++;
            }
            else if(mp[s[index]] >= mp[s[index + 1]]){
                ans += mp[s[index]];
                index++;
            }
            else{
                ans += (mp[s[index + 1]] - mp[s[index]]);
                index += 2;
            }
        }
        return ans;
    }
};