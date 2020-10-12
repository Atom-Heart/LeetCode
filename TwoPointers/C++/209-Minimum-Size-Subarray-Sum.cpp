/*方法一：滑动窗口*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int left = 0, right = 0;
        int sum = 0;
        int ans = INT_MAX;
        while(right < n){
            sum += nums[right];
            right++;
            while(sum >= s){
                ans = min(ans, right - left);
                sum -= nums[left];
                left++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
/*方法二：前缀和优化暴力法*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> sums(n, 0);
        sums[0] = nums[0];
        for(int i = 1; i < n; i++){
            sums[i] = nums[i] + sums[i - 1];
        }
        int min = INT_MAX;
        /*sums[j] - sums[i]表示nums[i + 1 ~ j]之和，但是我现在想要去算的是nums[i ~ j]的和，所以我需要
        s2 = s - nums[i]来表示nums[i]已经被加过了，第二个for循环里j = i就是表示只选了nums[i]这一个数所求出的和*/
        for(int i = 0; i < n; i++){
            int s2 = s - nums[i];
            for(int j = i; j < n; j++){
                if(sums[j] - sums[i] >= s2){
                    min = ::min(min, j - i + 1);
                }
            }
        }
        return min == INT_MAX ? 0 : min;
    }
};
/*方法三：利用二分搜索继续优化前缀和*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> sums(n, 0);
        sums[0] = nums[0];
        for(int i = 1; i < n; i++){
            sums[i] = nums[i] + sums[i - 1];
        }
        int min = INT_MAX;
        
        for(int i = 0; i < n; i++){
            int s2 = s - nums[i]; 
            /*
            if(sums[j] - sums[i] >= s2){//相当于找找出一个sums[j] >= sums[i] + s2
                min = ::min(min, j - i + 1);
            }
            */
            int index = binarySearch(sums, i, n - 1, sums[i] + s2);
            if(index != -1) min = ::min(min, index - i + 1);
        }
        return min == INT_MAX ? 0 : min;
    }
    int binarySearch(vector<int>& nums, int left, int right, int target){
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return nums[left] >= target ? left : -1;
    }
};
