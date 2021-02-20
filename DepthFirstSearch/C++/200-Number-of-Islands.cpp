class Solution {
public:
    vector<vector<bool>> used;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        used.resize(m, vector<bool>(n, false));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && used[i][j] == false){
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int x, int y){
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < 4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || used[new_x][new_y] || grid[new_x][new_y] == '0') continue;
            used[new_x][new_y] = true;
            dfs(grid, new_x, new_y);
        }
    }
};