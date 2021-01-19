/*暴力*/
class Solution {
public:
    int nthUglyNumber(int n) {
        int count = 0;
        int num = 1;
        while(1){
            if(isUgly(num)){
                count++;
                if(count == n) break;
            }
            num++;
        }
        return num;
    }
     bool isUgly(int num) {
        if(num == 0) return false;
        else if(num == 1 || num == 2 || num == 3 || num == 5) return true;
        if(num % 2 == 0 ){
            return isUgly(num / 2);    
        }
        else if(num % 3 == 0){
            return isUgly(num / 3);
        }
        else if(num % 5 == 0){
            return isUgly(num / 5);
        }
        return false;
    }
};
/*方法二：筛法*/
class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<int> s;
        s.insert(1);
        int ans = 1;
        int count = 0;

        while(count < n){
            if(s.find(ans) != s.end()){
                count++;
                s.insert(ans * 2);
                s.insert(ans * 3);
                s.insert(ans * 5);
            }
            ans++;
        }
        return ans - 1;
    }
};
/*方法三：堆*/
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(1);
        int count = 0;
        long long res = 1;
        while(count < n){
            res = pq.top();
            pq.pop();
            /*去重*/
            while(!pq.empty() && pq.top() == res){
                pq.pop();
            }
            count++;
            pq.push(res * 2);
            pq.push(res * 3);
            pq.push(res * 5);
        }
        return (int)res;
    }
};

/*方法四：三指针归并+DP*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;
        int index2 = 0, index3 = 0, index5 = 0;
        for(int i = 1; i < n; i++){
            int factor2 = 2 * ugly[index2];
            int factor3 = 3 * ugly[index3];
            int factor5 = 5 * ugly[index5];
            int min = ::min(::min(factor2, factor3), factor5);
            /*更新丑数序列*/
            ugly[i] = min;
            /*如果有多组数都等于min，指针都需要后移，从而保证ugly不会加入重复数字*/
            if(factor2 == min) index2++;
            if(factor3 == min) index3++;
            if(factor5 == min) index5++;
        }
        return ugly[n - 1];
    }
};