/*回溯：未剪枝版本*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> route;
        backTracking(candidates, route, 0, 0, target);
        return ans;
    }
    void backTracking(vector<int>& candidates, vector<int> route, int begin, int sum, int target){
        if(sum == target){
            ans.push_back(route);
            return;
        }
        else if(sum > target){
            return;
        }

        for(int i = begin; i < candidates.size(); i++){
            sum += candidates[i];
            route.push_back(candidates[i]);
            backTracking(candidates, route, i, sum, target);
            sum -= candidates[i];
            route.pop_back();
        }
    }
};
/*回溯：剪枝版本*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> route;
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, route, 0, 0, target);
        return ans;
    }
    void backTracking(vector<int>& candidates, vector<int> route, int begin, int sum, int target){
        if(sum == target){
            ans.push_back(route);
            return;
        }
        else if(sum > target){
            return;
        }

        for(int i = begin; i < candidates.size() && sum + candidates[i] <= target; i++){//这里进行了剪枝，因为一开始对容器进行了排序，所以如果sum加上candidates[i]大于了目标值，那么说明
                                                                                        //加上后面的值都会大于target，所以没有必要继续进行回溯过程
            sum += candidates[i];
            route.push_back(candidates[i]);
            backTracking(candidates, route, i, sum, target);
            sum -= candidates[i];
            route.pop_back();
        }
    }
};