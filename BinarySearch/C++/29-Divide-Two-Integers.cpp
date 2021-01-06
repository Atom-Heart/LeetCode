class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend < 0 && dividend == INT_MIN){//因为-2^31 / -1 = 2^31 - 1
                return INT_MAX;
            }
            else if(dividend > 0){
                return -dividend;
            }
        }
        int sign1 = dividend * 1 > 0 ? 1 : -1;
        int sign2 = divisor * 1 > 0 ? 1 : -1;
        int sign = sign1 * sign2 > 0 ? 1 : -1;//得出除法运算的结果的正负号
        
        if(dividend > 0) dividend = -dividend;//将除数和被除数都变为负数，防止越界
        if(divisor > 0) divisor = -divisor;

        int ans = 0;
        /*这道题的核心思想就是被除数能减去多少除数，一开始我是每次都让被除数减去一次除数，但这样会超时；所以可以让被除数都减去除数的2倍，直到被除数小于除数，然后再将除数重置为
        初始值*/
        while(dividend <= divisor){
            int temp = divisor;
            int i = 1;
            while(dividend <= temp){
                dividend -= temp;
                ans += i;
                i <<= 1;
                if(temp < INT_MIN / 2){/*防止越界，因为Leetcode不让对负数进行右移操作*/
                    break;
                }
                else{
                    temp *= 2;
                }
            }
        }
        return min(max(INT_MIN, sign * ans), INT_MAX);//这一句很关键
    }
};


/*
*思想就是二进制，设除数是y，被除数是x,被除数可以表示为: y*2^0 + y*2^1 + y*2^2 + y*2^n,然后被除数从高位向低位减，看能剪出多少个被除数
*/
class Solution {
public:
    int divide(int x, int y) {
        using LL = long long;
        vector<LL> exp;
        bool is_minus = false;

        if(x < 0 && y > 0 || x > 0 && y < 0) is_minus = true;
        LL a = abs((LL)x), b = abs((LL)y);
        for(LL i = b; i <= a; i = i + i) exp.push_back(i);
        LL res = 0;
        for(int i = exp.size() - 1; i >= 0; i--){
            if(a >= exp[i]){
                a -= exp[i];
                res += 1ll << i;
            }
        }
        if(is_minus) res = -res;
        if(res > INT_MAX || res < INT_MIN) res = INT_MAX;
        return res;
    }
};