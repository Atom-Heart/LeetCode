class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k >= n) return "0";
        
        string ans;
        for(int i = 0; i < num.size(); i++){
            while(ans.size() > 0 && ans.back() > num[i] && k-- > 0){
                ans.pop_back();
            }
            ans += num[i];
        }
        
        if(k > 0) ans = ans.substr(0, ans.size() - k);


        //cout<<ans<<endl;
        int i = 0;
        while(i < ans.size() - 1 && ans[i] == '0') {
            i++;
        }
        return ans.substr(i);
    }
};