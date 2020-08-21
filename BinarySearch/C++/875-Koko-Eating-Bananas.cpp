class Solution {
public:
    int findMax(vector<int>& piles){
        int max = 0;
        for(int i = 0; i < piles.size(); i++){
            if(max < piles[i]){
                max = piles[i];
            }
        }
        return max;
    }
    int calculateSum(vector<int>& piles, int speed){
        int sum = 0;
        for(int pile : piles){
            sum += (pile + speed - 1) / speed;//向上取整，sum代表吃完所有堆的香蕉的小时数，在分母上加上“分子-1”就可以变成向上取整的除法运算
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1;
        int right = findMax(piles) + 1;
        while(left < right){/*这里本身是线性查找，所以这里可以利用二分来进行优化*/
            int mid = left + (right - left) / 2;
            if(calculateSum(piles, mid) > H){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};