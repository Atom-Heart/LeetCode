class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(10, false));
        vector<vector<bool>> col(9, vector<bool>(10, false));
        vector<vector<bool>> box(9, vector<bool>(10, false));//有9个box，每个box里都有10个数
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if(row[i][num] == true) return false;//board[i][j]在第i行出现过了
                if(col[j][num] == true) return false;
                if(box[j / 3 + (i / 3) * 3][num] == true) return false;

                row[i][num] = true;
                col[j][num] = true;
                box[j / 3 + (i / 3) * 3][num] = true;
            }
        }
        return true;
    }
};