class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        string ans;

        for(int i = 0; i < num.size(); i++){
            while(!st.empty() && num[i] < st.top() && k != 0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        int n = ans.size();
        if(k != 0){
            ans = ans.substr(0, n - k);
        }

        int i = 0;
        while(ans.size() > 1 && ans[i] == '0'){
            i++;
        }
        ans = ans.substr(i);
        return ans.size() == 0 ? "0" : ans;
    }
};