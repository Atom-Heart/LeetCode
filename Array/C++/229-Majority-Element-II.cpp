/*方法一：排序后判断*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int target = nums.size() / 3;
        for(int i = 0; i < nums.size(); i++){
            int index = i;
            while(index + 1 < nums.size() && nums[index] == nums[index + 1]){
                index++;
            }
            if(index - i + 1 > target) ans.push_back(nums[i]);
            i = index;
        }
        return ans;
    }
};

/*摩尔投票法*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 0) return ans;
        /*初始化两个候选人*/
        int cand1 = nums[0], count1 = 0;
        int cand2 = nums[0], count2 = 0;
        /*配对阶段*/
        for(int num : nums){
            /*投票*/
            if(num == cand1){
                count1++;
                continue;
            }
            if(num == cand2){
                count2++;
                continue;
            }

            /*第一个候选人配对*/
            if(count1 == 0){
                cand1 = num;
                count1 = 1;
                continue;
            }
            /*第二个候选人配对*/
            if(count2 == 0){
                cand2 = num;
                count2 = 1;
                continue;
            }
            count1--;
            count2--;
        }
        /*计数阶段*/
        /*找到了两个候选人之后，需要确定票数否是大于N/3*/
        count1 = 0;
        count2 = 0;
        for(int num : nums){
            if(num == cand1) count1++;
            else if(num == cand2) count2++;
        }
        if(count1 > nums.size() / 3) ans.push_back(cand1);
        if(count2 > nums.size() / 3) ans.push_back(cand2);
        return ans;
    }
};