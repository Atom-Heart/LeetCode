class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> route;
        backTracking(1, route, 0, 0, k, n);
        return ans;
    }
    void backTracking(int begin, vector<int> route, int level, int sum, int k, int n){
        if(level == k && sum == n){
            ans.push_back(route);
            return;
        }
        for(int i = begin; i <= 9 && sum + i <= n; i++){
            sum += i;
            route.push_back(i);
            backTracking(i + 1, route, level + 1, sum, k, n);
            sum -= i;
            route.pop_back();
        }
    }
};