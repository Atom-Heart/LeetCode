class Solution {
public:
    set<vector<int>> st;
    vector<vector<int>> ans;
    vector<int> route;

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backTracking(nums, 0);
        for(auto it = st.begin(); it != st.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }
    
    void backTracking(vector<int>& nums, int begin){
        if(begin >= nums.size() && route.size() >= 2){
            if(st.find(route) == st.end()) st.insert(route);
            return;
        }
        
        if(route.size() >= 2 && st.find(route) == st.end()) st.insert(route);
        
        for(int i = begin; i < nums.size(); i++){
            if(route.size() == 0 || route[route.size() - 1] <= nums[i]){
                route.push_back(nums[i]);
                backTracking(nums, i + 1);
                route.pop_back();
            }
        }
    }
};