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