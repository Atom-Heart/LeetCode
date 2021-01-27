class Solution {
public:
    /*这个题的难点主要在于负数对正数的取余操作*/
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
        
        int prefix = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            prefix = (A[i - 1] + prefix) % K;
            if(prefix < 0) prefix += K;//关键
            ans += hash[prefix]++;
        }
        return ans;
    }
};