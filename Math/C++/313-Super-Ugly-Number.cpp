class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n);
        ugly[0] = 1;
        /*indexs[i]保存第i个指针的位置*/
        int len = primes.size();
        vector<int> indexs(len, 0);

        for(int i = 1; i < n; i++){
            /*找出n个指针指向的最小数字*/
            int min = INT_MAX;
            for(int j = 0; j < len; j++){
                int num = ugly[indexs[j]] * primes[j];
                if(num < min) min = num;
            }
            /*更新丑数数组*/
            ugly[i] = min;
            /*后移指针*/
            for(int j = 0; j < len; j++){
                if(ugly[indexs[j]] * primes[j] == min) indexs[j]++;
            }
        }
        return ugly[n - 1];
        
    }
};