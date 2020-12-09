class Solution {
    public:
    int singleNonDuplicate(vector<int> nums) {
        int left=0;
	    int right=nums.size()-1;
	    while(left<right){
	        int mid=left+(right-left)/2;
	        if(nums[mid] == nums[mid-1]){//中点跟左边的相等，则判断除开中点，左边还剩几位数；
                if((mid-left)%2 == 0){//若为偶数，则说明左边的存在答案值，改变right的值
                   right = mid-2;
               } else {//若为奇数，则说明右边的存在答案值，改变left的值
                   left = mid+1;
               }
           } else if(nums[mid] == nums[mid+1]){//中点跟右边的相等，则判断除开中点，右边还剩几位数；
               if((right-mid)%2 == 0){//若为偶数，则说明右边的存在答案值，改变left的值
                   left = mid+2;
               } else {//若为奇数，则说明左边的存在答案值，改变right的值
                   right = mid-1;
               }
           } else{//中点跟左右都不相等，直接返回
        	  return nums[mid];
           }
	    }
        return nums[right];
    }
};