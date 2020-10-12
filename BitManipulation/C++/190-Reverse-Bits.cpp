class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int k = 32;//因为前导0翻转之后是有意义的
        uint32_t ans = 0;
        while(k--){
            ans = ans | ((n & 1) << k);//n&1表示最后一位的数是0还是1，再将这个数左移相应的位数，然后再将ans的对应位置成0或1
            n >>= 1;
        }
        return ans;
        
    }
};