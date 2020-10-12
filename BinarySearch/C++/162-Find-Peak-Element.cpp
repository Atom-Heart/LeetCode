class Solution {
public:
	int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        else if(nums.size() == 2) return nums[0] > nums[1] ? 0 : 1;
		int left = 0, right = nums.size() - 1;//这里right必须要减一，因为搜索的区间不能到最后一个元素，因为需要
                                              //访问最后一个元素+1的位置，会发生越界
		int mid = (left + right) / 2;
		while (left < right) {//搜索区间是[left, right)
			mid = (left + right) / 2;
			if (nums[mid] < nums[mid + 1]) {//如果此时是递增的，那么说明峰值一定在mid后面那部分
				left = mid + 1;
			}
			else {//如果此时是递减的，那么峰值一定在mid前面那部分
				right = mid;
			}
		}
		return left;
	}
};