class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int num : nums) mp[num]++;
        vector<pair<int, int>> vec;
        for(auto [k, v] : mp){
            vec.push_back(make_pair(k, v));
        }

        sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            return a.second > b.second;
        });

        vector<int> ans;
        for(int i = 0; i < vec.size() && k; i++, k--){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};