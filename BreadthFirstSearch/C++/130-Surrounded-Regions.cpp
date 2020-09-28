/*我的思路是利用DFS或BFS，矩阵边缘的'O'相当于出口，如果board[i][j] == 'O',那就向上下左右去移动，如果能移动到矩阵边缘且边缘为'O'，说明这个board[i][j]可以变为'X'*/
/*答案的思路和我差不多，但是比我的巧妙很多，答案先将所有与边界的'O'联通的所有'O'全部置为'#'，这个找联通'O'的过程就用的DFS。然后再遍历整个数组，遇到'O'置'X'，遇到'#'置'O'*/
class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    void dfs(vector<vector<char>>& board, int x, int y){
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '#' || board[x][y] == 'X') return;
        board[x][y] = '#';
        dfs(board, x - 1, y);
        dfs(board, x + 1, y);
        dfs(board, x, y - 1);
        dfs(board, x, y + 1);
    }
    /*超时*/
    void bfs(vector<vector<char>>& board, int x, int y){
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        
        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();
            board[temp.first][temp.second] = '#';
            for(int i = 0; i < 4; i++){
                int new_x = temp.first + dx[i];
                int new_y = temp.second + dy[i];
                if(new_x < 0 || new_x >= board.size() || new_y < 0 || new_y >= board[0].size() || board[new_x][new_y] == '#' || board[new_x][new_y] == 'X') {
                    continue;
                }
                q.push(make_pair(new_x, new_y));
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return;
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                bool isEdge = (i == 0 || i == m - 1 || j == 0 || j == n - 1);
                if(isEdge && board[i][j] == 'O'){
                    bfs(board, i, j);
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};