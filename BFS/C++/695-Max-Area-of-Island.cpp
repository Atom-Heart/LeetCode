class Solution {
public:
    int ans = 0;
    int m, n;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    void BFS(vector<vector<int>>& grid, int x, int y){
        queue<pair<int ,int>> q;
        q.push(make_pair(x, y));
        grid[x][y] = -1;
        int cnt = 1;
        
        while(!q.empty()){
            auto item = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int new_x = item.first + dx[i];
                int new_y = item.second + dy[i];
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == 1){
                    q.push(make_pair(new_x, new_y));
                    grid[new_x][new_y] = -1;
                    cnt++;
                }
            }
        }
        //cout<<"x = "<<x<<" "<<"y = "<<y<<" "<<"cnt = "<<cnt<<endl;
        ans = max(ans, cnt);    
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                    BFS(grid, i, j);
            }
        }
        return ans;
    }
};