class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		if (nums.size() == 0) return {};
		vector<string> ans;
		for (int i = 0; i < nums.size();) {
			int index = i;
            /*找到连续的右边界*/
			while (index + 1 < nums.size() && nums[index + 1] == nums[index] + 1) {//这里有可能发生越界
				index++;
			}
            string str1 = to_string(nums[i]);
            string str2 = to_string(nums[index]);
			if (index == i) {
				ans.push_back(str1);
			}
			else {
				string str = "" + str1 + "->" + str2;
                ans.push_back(str);
			}
			i = index + 1;
		}
		return ans;
	}
};