/*
*多源BFS求最远距离
*方法一：多源扩散法
*难点1：为什么不从0出发去找1呢？
*/
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) q.push(make_pair(i, j));
            }
        }
        bool flag = false;
        pair<int, int> item = make_pair(-1, -1);
        while(!q.empty()){
            item = q.front();
            q.pop();
            int x = item.first;
            int y = item.second;
            for(int i = 0; i < 4; i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == 0){
                    grid[new_x][new_y] = grid[x][y] + 1;
                    flag = true;//表示存在海洋
                    q.push(make_pair(new_x, new_y));//继续搜索
                }
            }
        }
        if(!flag || item.first == -1) return -1;
        /*最后一个扩散到的海洋一定是离它最近的陆地单元格的距离最大*/
        return grid[item.first][item.second] - 1;
    }   
};

class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int steps = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) q.push(make_pair(i, j));
            }
        }
        if(q.size() == 0 || q.size() == m * n) return -1;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto item = q.front();
                q.pop();
                int x = item.first;
                int y = item.second;
                for(int i = 0; i < 4; i++){
                    int new_x = x + dx[i];
                    int new_y = y + dy[i];
                    if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == 0){
                        grid[new_x][new_y] = 1;
                        q.push(make_pair(new_x, new_y));
                    }
                }
            }
            steps++;

        }
        return steps - 1;
    }
};