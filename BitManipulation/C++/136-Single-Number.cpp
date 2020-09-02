/*方法一：先排序，然后再找（low）*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size()){
            if(i == nums.size() - 1) return nums[i];
            if(nums[i] != nums[i + 1]){
                return nums[i];
            }
            i += 2;
        }
        return nums[i - 2];
    }
};

/*方法二*/
/*利用异或操作，利用异或的交换律和结合律，0异或一个数还是那个数，一个数异或它自己为0*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res = res ^ nums[i];
        }
        return res;
    }
};