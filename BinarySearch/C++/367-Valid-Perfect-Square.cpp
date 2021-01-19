class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0) return false;
        int left = 1, right = num;
        while(left < right){
            int mid = (left + (long long)right) >> 1;
            if(mid >= num / mid) right = mid;
            else left = mid + 1;
        }
        return left == sqrt(num);
    }
};