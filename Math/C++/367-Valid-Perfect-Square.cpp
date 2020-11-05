class Solution {
public:
    bool isPerfectSquare(int num) {
        int res = mySqrt(num);
        cout<<res;
        return res * res == num;
    }
    int mySqrt(int num){
        long long left = 0;
        long long right = num / 2 + 1;
        while(left < right){
            long long mid = (left + right + 1) / 2;
            long long cur = mid * mid;
            if(cur > num){
                right = mid - 1;
            }
            else if (cur < num){
                left = mid;
            }
            else{
                return mid;
            }
        }
        return left;
    }
};