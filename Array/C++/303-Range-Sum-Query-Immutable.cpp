class NumArray {
public:
    NumArray(vector<int>& nums) {
        sums = new int[nums.size() + 1];
        sums[0] = 0;
        for(int i = 1; i <= nums.size(); i++){
            sums[i] = nums[i - 1] + sums[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
private:
    int* sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */