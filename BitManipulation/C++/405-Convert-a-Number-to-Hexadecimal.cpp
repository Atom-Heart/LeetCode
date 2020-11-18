class Solution {
public:
    string toHex(unsigned int num) {
        if(!num) return "0";
        string ans, nums = "0123456789abcdef";
        while(num){
            ans += nums[num & 0xf];
            num >>= 4;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};