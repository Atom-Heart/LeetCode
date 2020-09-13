class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*if(n == 1) return true;
        else if(n % 2 == 1) return false;
        else if(n == 0) return false;
        return isPowerOfTwo(n / 2);*/
        return n > 0 && (n & (n - 1)) == 0; //n如果是二的幂次，则n的二进制最高位必为1，n - 1的最高位为0，其余位必为1
    }
};