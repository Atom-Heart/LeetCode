/*贪心，类比找零问题*/

class Solution {
public:
    string intToRoman(int num) {
        map<int, string> mp;
        mp[1] = "I";
        mp[4] = "IV";
        mp[5] = "V";
        mp[9] = "IX";
        mp[10] = "X";
        mp[40] = "XL";
        mp[50] = "L";
        mp[90] = "XC";
        mp[100] = "C";
        mp[400] = "CD";
        mp[500] = "D";
        mp[900] = "CM";
        mp[1000] = "M";
        string ans = "";

        for(auto it = mp.rbegin(); it != mp.rend(); it++){
            int use = num / it -> first;//看当前面额最多能拿几张
            num = num - it -> first * use;//更新一下数据
            while(use != 0){
                ans += it -> second;
                use--;
            }
        }
        return ans;
        
    }
};