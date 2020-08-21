class Solution {
public:
    int calculateSum(vector<int>& weights, int D, int cap){
        int i = 0;
        for(int day = 0; day < D; day++){
            int maxCap = cap;
            while((maxCap -= weights[i]) >= 0){
                i++;
                if(i == weights.size()){
                    return true;
                }
            }
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int right = 0;//右边界
        int left = 1;
        int sum = 0;
        for(auto weight : weights){
            sum += weight;
        }
        right += sum;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(calculateSum(weights, D, mid)){
                right = mid;   
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};