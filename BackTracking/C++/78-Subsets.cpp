class Solution {
public:
	vector<vector<int>> ans;
	vector<int> route;//记录回溯的路径
	void backTracking(vector<int>& nums, vector<int> route, int level) {
		ans.push_back(route);
		for (int i = level; i < nums.size(); i++) {
			route.push_back(nums[i]);
			backTracking(nums, route, i + 1);
			route.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		backTracking(nums, route, 0);
		return ans;
	}
};