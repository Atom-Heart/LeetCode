class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& route, vector<bool>& use){
        if(route.size() == nums.size()){
            res.push_back(route);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!use[i]){//如果nums[i]已经在路径中了，不能再用了，因为一个数字只能被用一次
                continue;
            }
            if(i > 0 && nums[i - 1] == nums[i] && use[i - 1]){//去重
                continue;
            }
            route.push_back(nums[i]);//将nums[i]加入到路径中
            use[i] = false;//标记nums[i]不可使用

            backtrack(nums, route, use);//进行下一次回溯

            route.pop_back();//将路径的状态恢复
            use[i] = true;//将nums[i]标记为可用
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> route;
        vector<bool> use(nums.size(), true);//用来标记某个位置数字是否可选
        sort(nums.begin(), nums.end());
        backtrack(nums, route, use);
        return res;
    }
};


/*
举个例子:输入   nums   = [1, 1, 2]
                index  =  0  1  2
因为nums中含有重复的数字，所以可能会出现重复的排列，这道题的主要问题就是怎么解决由于重复的数字导致出现重复排列的问题

首先来考虑下标能组成多少个排列，因为下标是不会重复的，便于理解产生重复的原因

排列        下标            元素
1       0   1   2   ->    1   1   2
2       0   2   1   ->    1   2   1
3       1   0   2   ->    1   1   2
4       1   2   0   ->    1   2   1
5       2   0   1   ->    2   1   1
6       2   1   0   ->    2   1   1

其中排列1、3相同，2、4相同，5、6相同。



*/