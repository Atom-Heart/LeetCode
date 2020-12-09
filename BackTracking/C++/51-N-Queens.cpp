class Solution {
public:
    bool vaild(vector<string>& board, int row, int col){
        int n = board.size();
        /*如果col这一列存在其他queen*/
        for(int i = 0; i < n; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        /*因为我刚刚选的这一行，所以这一行肯定只有一个queen，所以不用判断行*/

        /*判断右上斜线有没有queen*/
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        /*判断左上斜线有没有queen*/
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    void backtrack(vector<string> &board, int row){
        if(row == board.size()){
            res.push_back(board);
            return;
        }

        int n = board[row].size();
        for(int col = 0; col < n; col++){
            if(!vaild(board, row, col)) continue;
            board[row][col] = 'Q';
            backtrack(board, row + 1);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }
private:
    vector<vector<string>> res;
};