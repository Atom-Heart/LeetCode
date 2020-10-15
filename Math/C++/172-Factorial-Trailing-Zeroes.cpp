class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int divisior = 5;
        while(divisior <= n){
			/*125/5就是计算出有多少个像5，10，15，20这些5的倍数，它们可以提供一个5*/
			/*但是25,50，75能提供两个5；125能提供3个5*/
			/*所以先计算出能提供一个5的数有多少，然后再计算能提供两个5的数有多少，最后累加起来就是结果*/
            ans += n / divisior;
            divisior *= 5;
        }
        return ans;

    }
};