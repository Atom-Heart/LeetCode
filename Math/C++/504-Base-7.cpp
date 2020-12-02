class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        int flag = 1;
        if(num < 0) flag = -1;
        num = abs(num);
        string ans;
        while(num){
            ans += to_string(num % 7);
            num /= 7;
        }
        reverse(ans.begin(), ans.end());
        return flag == 1 ? ans : "-" + ans;
    }
};