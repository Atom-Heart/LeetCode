class Solution {
public:
    double myPow(double x, int n) {
        using LL = long long;
        bool is_minus = false;
        if(n < 0) is_minus = true;
        double ans = 1;
        for(LL k = abs(n); k > 0; k >>= 1){
            //cout<<k<<endl;
            if(k & 1) ans *= x;
            x *= x;
        }
        
        return is_minus == true ? 1 / ans : ans;
    }
};