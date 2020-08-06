class Solution {
public:
/*技巧(a * b) % k = ((a % k) * (b % k)) % k */
    int myPow(int a, int k){//快速幂方法
        if(k == 0) return 1;
        a %= 1337;
        if(k & 1) return (a * myPow(a, k - 1)) % 1337;
        return myPow(a * a, k / 2) % 1337;//如果不在这里取余，那就会溢出
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int back = b[b.size() - 1];
        b.pop_back();
        int num1 = myPow(a, back);
        int num2 = myPow(superPow(a, b), 10);
        return (num1 * num2) % 1337;
        
    }
};