/*方法一：迭代*/
class Solution {
public:
    bool isPrime(int n){
        for(int i = 2; i * i <= n; i++){// i * i <= n，这很关键
            if(n % i == 0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        if(n == 0 || n == 1 || n == 2) return 0;
        int ans = 0;
        for(int i = 2; i < n; i++){
            if(isPrime(i)) {
                ans++;
            }
        }
        return ans;
    }
};

/*方法二：空间换时间*/
class Solution {
public:
    bool isPrime(int n){
        for(int i = 2; i * i <= n; i++){//优化
            if(n % i == 0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        vector<bool> memo(n, true);
        for(int i = 2; i * i < n; i++){//优化，之所以可以优化的理由和isPrime的一样
            if(isPrime(i)){
                for(int j = i * i; j < n; j += i){//优化 之前是"int j = 2 * i"，每次j都是i的倍数
                    memo[j] = false;
                }
            }
        }

        int ans = 0;
        for(int i = 2; i < n; i++){
            if(memo[i]) ans++;
        }
        return ans;
    }
};