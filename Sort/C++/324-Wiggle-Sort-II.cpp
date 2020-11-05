class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());

	    vector<int> temp = nums;
	    int n = nums.size();
	    int mid = n%2?n/2:(n/2-1);
	    n = n - 1;
	    for (int i = 0; i < nums.size(); i++)
	    {
	    	nums[i] = i % 2 ? temp[n--]: temp[mid--] ;
    	}
    }
};
