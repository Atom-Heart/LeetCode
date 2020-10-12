/*方法一：每次判断数字的最低位是不是1*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n != 0){
            cout<<n<<endl;
            if(n & 1 == 1) ans++;
            n = n >> 1;
        }
        return ans;
        
    }
};

/*方法二：依次把数字最右边的1置0*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n){
            n = n & (n - 1);
            ans++;
        }
        return ans;
    }
};