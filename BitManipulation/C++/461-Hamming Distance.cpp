class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int num = x ^ y;//把不相等的位全部置为1
        while(num > 0){
            if(num & 1 == 1){
                res++;
            }
            num >>= 1;//算术右移
        }
        return res;

    }
};