class Solution {
public:
    int ans = 0;
    int findPairs(vector<int>& nums, int k) {
        /*排序*/
        sort(nums.begin(), nums.end());
        /*
        int len = 1;
        int left = 1, right = 1;
        while(right < nums.size()){
            if(nums[right] == nums[right - 1]){
                right++;
            }
            else{
                nums[left] = nums[right];
                left++;
                right++;
                len++;
            }
        }
        nums = vector<int>(nums.begin(), nums.begin() + len);
        */
        set<pair<int, int>> st;

        for(int i = 0; i < nums.size() - 1; i++){
            int num1 = nums[i];
            int left = i + 1, right = nums.size();
            while(left < right){
                int mid = (left + right) >> 1;
                int x = nums[mid] - nums[i];
                x = abs(x);
                if(x < k){
                    left = mid + 1;
                }
                else if(x == k){
                    if(st.count(make_pair(nums[i], nums[mid])) == 0){
                        ans++;
                        st.insert(make_pair(nums[i], nums[mid]));
                    }
                    break;
                }
                else{
                    right = mid;
                }
            }
        }
        return ans;
    }
};