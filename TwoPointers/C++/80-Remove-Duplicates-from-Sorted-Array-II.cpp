/*我自己写的*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2) {
			return nums.size();
		}
		int count = 0;//如果当前待插入数字的重复次数

		int len = 1;
		int left = 1, right = 1;
		while (right < nums.size()) {
			if (nums[right] == nums[right - 1]) {
				if (count == 0) {
					count++;
					nums[left] = nums[right];
					len++;
					left++;
				}
			}
			else {
				nums[left] = nums[right];
				left++;
				len++;
				count = 0;
			}
			right++;
		}
		return len;

	}
};

/*好的写法*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2){
            return nums.size();
        }
        int index = 2;//待插入位置的下标
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] != nums[index - 2]){//因为可以允许两个重复的数字，所以会有一下几种情况：1.index[i]只出现了一次 2.index[i]出现两次 3.index[i]出现三次及以上
                nums[index++] = nums[i];   //所以在nums[i]出现了三次及以上的情况下index不会右移
            }
        }
        return index;
    }
};