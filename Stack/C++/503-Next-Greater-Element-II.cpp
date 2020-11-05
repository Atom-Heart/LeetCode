class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        int n = nums.size();
        stack<int> st;
		/*思想就是在原数组最后再补一个原数组，但不用真的去补，可以通过循环取余操作模拟*/
        for(int i = 2 * n - 1; i >= 0; i--){
            while(!st.empty() && nums[i % n] >= st.top()){
                st.pop();
            }
            if(st.empty()){
                ans[i % n] = -1;
            }
            else{
                ans[i % n] = st.top();
            }
            st.push(nums[i % n]);
        }
        return ans;

    }
};