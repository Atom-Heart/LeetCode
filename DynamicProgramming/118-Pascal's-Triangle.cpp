class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return {};
        else if(numRows == 1) return {{1}};
        else if(numRows == 2) return {{1}, {1, 1}};
        vector<int> dp = {1, 1};
        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1, 1});

        for(int i = 2; i < numRows; i++){
            vector<int> cur;
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i) cur.push_back(1);
                else{
                    cur.push_back(dp[j] + dp[j - 1]);
                }
            }
            dp = cur;
            ans.push_back(dp);
        }
        return ans;
    }
};