class Solution {
public:
    /* n * n <= x*/
    /*一拿到手分析一下区间就知道用模板二*/
    int mySqrt(int x) {
        using LL = long long;
        LL left = 0, right = x;
        while(left < right){
            long long mid = (left + right + 1) / 2;
            if(mid <= x / mid) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};