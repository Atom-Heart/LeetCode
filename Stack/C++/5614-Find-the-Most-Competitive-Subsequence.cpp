class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        if(nums.size() == 0 || nums.size() == 1) return nums;
        vector<int> ans;
        stack<int> st;
        int n = nums.size();
        k = n - k;
        
        for(int i = 0; i < nums.size(); i++){
            while(!st.empty() && nums[i] < st.top() && k != 0){
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        while(k != 0){
            k--;
            ans.pop_back();
        }
        return ans;
    }
};