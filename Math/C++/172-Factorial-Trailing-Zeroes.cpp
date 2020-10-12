class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int divisior = 5;
        while(divisior <= n){
            ans += n / divisior;
            divisior *= 5;
        }
        return ans;

    }
};