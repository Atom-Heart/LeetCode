/*方法一：换底公式*/
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0) return false;
        
        double temp = log10(num) / log10(4);
        return temp == floor(temp) ? true : false;

    }
};

/*方法二：位操作*/
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 1) return false;
        else if(num & (num - 1)) return false;//如果不是二的幂
        
        return num % 3 == 1 ? true : false;
    }
};

