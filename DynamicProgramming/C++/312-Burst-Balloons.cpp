/*1.回溯（才过了13个用例就超时了）*/
class Solution {
public:
    int ans = INT_MIN;
    void backTracking(vector<int>& nums, int route, int level, vector<bool>& used){
        if(level == nums.size()){
            cout<<route<<endl;
            if(route > ans) ans = route;
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            /*第i个气球已经打过了*/
            if(used[i] == true) continue;
            /*打破第i个气球*/
            used[i] = true;
            /*寻找相邻的气球*/
            int left = 1, right = 1;
            for(int j = i - 1; j >= 0; j--){
                if(used[j] == false) {
                    left = nums[j];
                    break;
                }
            }
            for(int j = i + 1; j < nums.size(); j++){
                if(used[j] == false){
                    right = nums[j];
                    break;
                } 
            }

            /*累加*/
            int sum = nums[i] * left * right;
            backTracking(nums, route + sum, level + 1, used);
            used[i] = false;
        }
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n, false);
        backTracking(nums, 0, 0, used);
        return ans;
    }
};

/*2.记忆化回溯*/
class Solution {
public:
    int ans = INT_MIN;
    int maxCoins(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int len = nums.size();
        /*构造一个新的数组出来，因为要给左右两边的数模拟出一个边界*/
        vector<int> nums1(len + 2);
        len = nums1.size();
        nums1[0] = 1;
        nums1[len - 1] = 1;
        for(int i = 1; i < len - 1; i++){
            nums1[i] = nums[i - 1];
        }

        vector<vector<int>> memo(len, vector<int>(len, 0));
        return helper(nums1, 0, len - 1, memo);
    }

    int helper(vector<int>& nums, int begin, int end, vector<vector<int>>& memo){
        /*递归边界，最小子问题*/
        if(begin == end - 1){
            return 0;
        }
        /*缓存，避免计算*/
        if(memo[begin][end] != 0){
            return memo[begin][end];
        }
        int max = 0;
        for(int i = begin + 1; i < end; i++){
            int temp = helper(nums, begin, i, memo) + helper(nums, i, end, memo) + nums[begin] * nums[i] * nums[end];
            if(temp > max) max = temp;
        }
        memo[begin][end] = max;
        return max;
    }
};

