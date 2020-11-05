/*方法一：复制原数组*/
class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0, -1, -1, 1, 1};
    vector<int> dy = {0, 0, -1, 1, -1, 1, -1 ,1};

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> memo = board;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int count = 0;
                for(int k = 0; k < 8; k++){
                    int new_x = i + dx[k];
                    int new_y = j + dy[k];
                    if(new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) continue;
                    if(memo[new_x][new_y] == 1) count++;
                }
                
                if(board[i][j] == 1){
                    if(count < 2 || count > 3) board[i][j] = 0;
                    else if(count == 2 || count == 3) continue;
                }
                else{
                    if(count == 3) board[i][j] = 1;
                }
            }
        }
    }
};

/*方法二：标记法*/
/*如果由1变为0则变为-1,由0变1则为2*/
class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0, -1, -1, 1, 1};
    vector<int> dy = {0, 0, -1, 1, -1, 1, -1 ,1};
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int count = 0;
                for(int k = 0; k < 8; k++){
                    int new_x = i + dx[k];
                    int new_y = j + dy[k];
                    if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n){
                        if(board[new_x][new_y] == 1 || board[new_x][new_y] == -1) count++;
                    }
                }
                
                if(board[i][j] == 1){
                    if(count < 2 || count > 3) board[i][j] = -1;
                }
                else{
                    if(count == 3) board[i][j] = 2;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 2) board[i][j] = 1;
                else if(board[i][j] == -1) board[i][j] = 0;
            }
        }
    }
};

