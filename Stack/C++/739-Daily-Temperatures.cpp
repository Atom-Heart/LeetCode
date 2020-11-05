class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && T[i] >= T[st.top()]){
                st.pop();
            }
            
            ans[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return ans;
    }
};