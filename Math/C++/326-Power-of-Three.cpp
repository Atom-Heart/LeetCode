class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        double temp = log10(n) / log10(3);
        return temp == floor(temp) ? true : false;

    }
};