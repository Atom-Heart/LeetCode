//方法一：先排序，后比较
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp;
        for(auto num : nums){
            temp.push_back(num);
        }
        int left = 0;
        int right = nums.size() - 1;
        sort(temp.begin(), temp.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != temp[i]){
                left = i;
                break;
            }
            if(i == nums.size() - 1){
                left = nums.size() - 1;
            }
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] != temp[i]){
                right = i;
                break;
            }
            if(i == 0){
                right = 0;
            }
        }
        if(right == 0 && left == nums.size() - 1){
            return 0;
        }
        return right - left + 1;

    }
};

//方法二：双指针
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int max_num = INT_MIN;
        int min_num = INT_MAX;
        int left = nums.size() - 1;//左边界从后向前更新
        int right = 0;//右边界从前向后更新

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < max_num){//前面的最大值大于当前位置的数，说明当前位置需要排序，这样就可以保证left之后的所有数字都是递增而且都是大于left之前的数字的
                right = i;
            }
            else{
                max_num = nums[i];
            }
        }

        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] > min_num){//当前的值大于当前位置之后所有元素的最小值，说明这个值放在这里不合适，需要排序
                left = i;
            }
            else{//如果这个值比当前位置之后的所有元素的最小值还小，那么这个值放在这里是没错的。不用排序
                min_num = nums[i];
            }
        }

        if(left == nums.size() - 1 && right == 0){//
            return 0;
        }
        return right - left + 1;
    }
};