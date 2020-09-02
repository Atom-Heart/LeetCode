
/*记忆化递归，超时
这个算法的时间复杂度是N2，递归算法的时间复杂度等于递归的深度乘每次递归的时间复杂度*/
class Solution {
public:
    int dp(vector<int> nums, vector<int>& memo, int begin){
        if(begin >= nums.size() - 1){//说明走到最后一个位置了
            return 0;
        }
        if(memo[begin] != nums.size()){//之前已经计算过了
            return memo[begin];
        }
        int step = nums[begin];//当前位置我能走的最大步数
        for(int i = 1; i <= step; i++){/*这里可以优化，没有必要遍历每个能到达的位置，只需要选择一个最有潜力的位置即可
		所谓最有潜力，就是在当前位置能到达的位置里选择一个可以走的最远的位置*/
            int subProblem = dp(nums, memo, begin + i);//下一个位置到终点所需的最小步数
            memo[begin] = min(memo[begin], subProblem + 1);
        }
        return memo[begin];
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, n);//范围[0, n - 1], 初始值都为n
        return dp(nums, memo, 0);//返回从零开始走到最后所需的最小步数
    }
};

/*贪心一，不好写*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int end = 0, farthest = 0;
        int jump = 0;
        for(int i = 0; i < n - 1; i++){
            farthest = max(farthest, nums[i] + i);
            if(end == i){
                jump++;
                end = farthest;
            }
        }
        return jump;
    }
};

/*贪心二*/
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        vector<int> memo(nums.size());
        for(int i = 0; i < nums.size(); i++){//计算每个位置能够到达的最远位置
            memo[i] = i + nums[i];
        }
        int cur_max = memo[0];//当前能跳到的最远位置,相当于已经跳了一次了，所以才把jump初始化为1
        int next_max = memo[0];//下次能跳到的最远位置
        int jump = 1;//最小跳跃次数
        for(int i = 1; i < memo.size(); i++){
            if(i > cur_max){//必须超过当前最大位置，才会进行下一跳
                ++jump;
                cur_max = next_max;//更新下一跳的最大位置
            }
            if(memo[i] > next_max){//在当前这一跳的范围内寻找最有潜力的那一个位置（也就是跳的最远的那个位置）
                next_max = memo[i];
            }
        }
        return jump;
    }
};