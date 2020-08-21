class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int div = 1;
        /*算出最小的n位数->10, 100, 1000...*/
        while(x / div >= 10) div *= 10;

        while(x > 0){
            int left = x / div;//获得首位
            int right = x % 10;//获得尾位
            if(left != right) return false;
            x = (x % div) / 10;//去除首位和尾位
            div /= 100;//除去两位
        }
        return true;
    }
};