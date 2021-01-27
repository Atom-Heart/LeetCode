class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<int> ans;
        
        while(n--){
            if(k - 1 <= n * 26){
                ans.push_back(1);
                k -= 1;
            }
            else{
                if(n == 0){
                    ans.push_back(k);
                }
                else{
                    int x = k - n * 26;
                    ans.push_back(x);
                    k -= x;
                }
            }
        }
        
        string str;
        for(auto num : ans){
            str += ('a' + (num - 1));
        }
        return str;

    }
};