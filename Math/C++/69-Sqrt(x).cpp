class Solution {
public:
    int ans = 0;
    int mySqrt(int x) {
        /*为了照顾0，左边界要设置为0*/
        long long left = 0;
        /*为了照顾1，右边界要设置为1*/
        long long right = x / 2 + 1;

        while(left < right){
            /*这里一定要求的是右中位数*/
            long long mid = (left + right + 1) >> 1;
            long long cur = mid * mid;
            if(cur > x){
                right = mid - 1;
            }
            else if(cur < x){
                left = mid;
            }
            else{
                return mid;
            }
        }
        return left;
    }
};