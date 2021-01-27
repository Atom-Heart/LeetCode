class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> hash;
        int m = wall.size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < wall[i].size() - 1; j++){
                if(j == 0) {
                    hash[wall[i][j]]++;
                    continue;
                }
                wall[i][j] += wall[i][j - 1];
                hash[wall[i][j]]++;
            }
        }
        int ans = 0;
        for(auto [k, v] : hash){
            ans = max(ans, v);
        }
        return m - ans;
    }
};