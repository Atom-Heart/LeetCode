class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> used;//去重
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> route;
        backTracking(candidates, 0, route, 0, target);
        return ans;
    }
    void backTracking(vector<int>& candidates, int begin, vector<int> route, int sum, int target){
        if(sum == target ) {
            if(used.find(route) == used.end()){
                ans.push_back(route);
                used.insert(route);
            }
            return;
        }
        
        for(int i = begin; i < candidates.size() && sum + candidates[i] <= target; i++){//剪枝
            sum += candidates[i];
            route.push_back(candidates[i]);
            backTracking(candidates, i + 1, route, sum, target);//i+1代表每个数字只用一次
            route.pop_back();
            sum -= candidates[i];
        }
    }
};