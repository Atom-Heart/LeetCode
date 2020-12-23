class Solution {
public:
    int func(vector<int>& nums, int n, int fre){
        int i = 0, j = 0;
        while(i < nums.size()){
            if(nums[i] == n) {
                break;
            }
            i++;
        }
        int cnt = 0;
        j = i;
        while(j < nums.size()){
            if(nums[j] == n){
                cnt++;
                if(cnt == fre) break;
            }
            j++;
        }
        return j - i + 1;
    }
    int findShortestSubArray(vector<int>& nums) {
        vector<int> n;//出现最多次数的数的个数可能有多个
        int fre = 0;
        map<int, int> mp;
        for(int num : nums){
            mp[num]++;
            if(mp[num] == fre){
                n.push_back(num);
            }
            else if(mp[num] > fre){
                n.clear();
                n.push_back(num);
                fre = mp[num];
            }
        }
        int ans = INT_MAX;
        for(auto num : n){
            ans = min(func(nums, num, fre), ans);
        }
        return ans;
    }
};