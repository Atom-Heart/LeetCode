class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0.0;
        if(n == 0) return 1.0;
        long num = n;//这一句必须要有，不然报越界错误
        if(num < 0){
            x = 1 / x;
            num = -num;
        }
        double res = 1.0;
        while(num){
            if(num & 1) res *= x;
            x *= x;
            num >>= 1;
        }
        return res;
    }
};