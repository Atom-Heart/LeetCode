/*暴力法（超时）*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n) return m & n;
        int ans = m & (m + 1);
        int i = m + 2;
        while(i <= n){
            ans &= i;
            i++;
        }
        return ans;
    }
};
/*经验题*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n) return m & n;
        int ans = m & (m + 1);
        int i = m + 2;
        while(i <= n){
            ans &= i;
            i++;
        }
        return ans;
    }
};