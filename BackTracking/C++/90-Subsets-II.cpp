class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    vector<int> route;

    void backTracking(vector<int> nums, vector<int>& route, int level){
        for(int i = level; i < nums.size(); i++){
            route.push_back(nums[i]);
            if(s.find(route) == s.end()){
                ans.push_back(route);
            }
            s.insert(route);
            backTracking(nums, route, i + 1);
            route.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.push_back({});
        sort(nums.begin(), nums.end());
        backTracking(nums, route, 0);
        return ans;
    }
};