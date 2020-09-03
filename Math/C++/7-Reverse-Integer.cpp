/*我一开始的想法还判断了输入数据的正负，这是完全没有必要的*/
/*这道题的溢出点在于ans * 10，那么就要再乘10之前判断是否存在溢出*/
/*INT_MAX是以7结尾的，INT_MIN是以8结尾的*/
/*如果能用long的话，那就很好处理了，只要在返回时判断是否溢出就可以*/

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0){
            int pop = x % 10;
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && pop > 7)){
                return 0;
            }
            if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && pop < -8)){
                return 0;
            }
            ans = ans * 10 + pop;
            x /= 10;
        }
        return ans;
    }
};