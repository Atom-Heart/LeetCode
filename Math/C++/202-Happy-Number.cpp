class Solution {
public:
    int helper(int n){
        int ans = 0;
        while(n){
            int num = n % 10;
            ans += num * num;
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = helper(slow);
            fast = helper(fast);
            fast = helper(fast);
        }while(slow != fast);
        return slow == 1;
    }
};