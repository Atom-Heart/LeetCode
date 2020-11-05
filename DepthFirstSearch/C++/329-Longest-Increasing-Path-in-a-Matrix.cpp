/*方法一：DFS*/
class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int ans = 1;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(matrix, i, j, 1);
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& matrix, int x, int y, int level){
        if(level > ans) ans = level;

        for(int i = 0; i < 4; i++){
            int m = matrix.size();
            int n = matrix[0].size();
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && matrix[new_x][new_y] > matrix[x][y]){
                dfs(matrix, new_x, new_y, level + 1);
            }
        }
    }
};
/*方法二：DFS+记忆化*/
class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int ans = 1;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> memo(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(memo[i][j] == 0){
                    memo[i][j] = dfs(matrix, i, j, memo);
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(memo[i][j] > ans) ans = memo[i][j];
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& memo){
        int base = 1;
        int step = 0;
        for(int i = 0; i < 4; i++){
            int m = matrix.size();
            int n = matrix[0].size();
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && matrix[new_x][new_y] > matrix[x][y]){
                if(memo[new_x][new_y] == 0){
                    memo[new_x][new_y] = dfs(matrix, new_x, new_y, memo);
                }

                if(memo[new_x][new_y] > step){
                    step = memo[new_x][new_y];
                }
            }
        }
        return base + step;
    }
};

/*方法三：拓扑排序, 用的是出度而不是入度，因为出度能剪掉很多枝*/
class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> outdegree(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < 4; k++){
                    int new_x = i + dx[k];
                    int new_y = j + dy[k];
                    if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && matrix[i][j] < matrix[new_x][new_y]){
                        ++outdegree[i][j];
                    }
                }
            }
        }

        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(outdegree[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        int ans = 0;

        while(!q.empty()){
            ans++;
            int len = q.size();
            for(int i = 0; i < len; i++){
                auto node = q.front();
                q.pop();
                int x = node.first, y = node.second;
                for(int k = 0; k < 4; k++){
                    int new_x = x + dx[k];
                    int new_y = y + dy[k];

                    if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && matrix[new_x][new_y] < matrix[x][y]){
                        outdegree[new_x][new_y]--;
                        if(outdegree[new_x][new_y] == 0){
                            q.push({new_x, new_y});
                        }
                    }
                }
            }
        }
        return ans;

    }
};