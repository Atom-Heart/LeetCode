class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int t = 0;
        for(int i = 0; i < num1.size() || i < num2.size(); i++){
            if(i < num1.size()) t += (num1[i] - '0');
            if(i < num2.size()) t += (num2[i] - '0');
            ans += to_string(t % 10);
            t /= 10;
        }
        if(t) ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};