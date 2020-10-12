/*方法一：回溯*/
class Solution {
public:
    /*这个dx和dy一开始弄错了，导致我调了半天*/
    vector<int> dx = { -1, 1, 0, 0 };
	vector<int> dy = { 0, 0, -1, 1 };
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        /*每个字母都当成入口试一下*/
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    string route;//记录访问过的路径
                    vector<vector<bool>> memo(m, vector<bool>(n, false));//记录已经访问过的字母
                    memo[i][j] = true;
                    route += board[i][j];
                    if(backtracking(board, word, route, i, j, 0, memo)) return true;
                }
            }
        }
        return false;
    }

    bool backtracking(vector<vector<char>>& board, string word, string& route, int x, int y, int level,
    vector<vector<bool>>& memo)
    {
        if(level == word.size() - 1) return true;
        for(int i = 0; i < 4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x < 0 || new_x >= board.size() || new_y < 0 || new_y >= board[0].size()){//这里一开始写错了
                continue;
            }
            if(memo[new_x][new_y] == false && board[new_x][new_y] == word[level + 1]){
                memo[new_x][new_y] = true;
                route += board[new_x][new_y];
                if(backtracking(board, word, route, new_x, new_y, level + 1, memo)){
                    return true;
                } 
                else{
                    route = route.substr(0, route.size() - 1);
                    memo[new_x][new_y] = false;
                }
            }
        }
        return false;
    }
};

/*方法二：DFS*/
class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> memo(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(DFS(board, word, i, j, 0, memo)){
                    return true;
                }
            }
        }
        return false;
    }
    bool DFS(vector<vector<char>>& board, string word, int x, int y, int level, vector<vector<bool>>& memo){
        if(level == word.size() - 1){
            return board[x][y] == word[level];
        }

        if(board[x][y] == word[level]){
            memo[x][y] = true;
            for(int i = 0; i < 4; i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x < 0 || new_x >= board.size() || new_y < 0 || new_y >= board[0].size() || memo[new_x][new_y] == true){
                    continue;
                }
                if(DFS(board, word, new_x, new_y, level + 1, memo)){
                    return true;
                }
            }
            memo[x][y] = false;
        }
        return false;
    }
};