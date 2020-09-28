/*方法一：记录为0的坐标，空间复杂度为O(MN)，因为如果这个矩阵全为0，那么需要MN个空间保存坐标*/
/*方法二：分别记录为0的坐标的行和列，如果重复了就不用再保存*/
/*方法三：用矩阵的第一行和第一列用来标记某列某行是否存在0*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        bool row_flag = false;
        bool col_flag = false;
        /*第一行有没有自带的0*/
        for(int i = 0; i < col; i++){
            if(matrix[0][i] == 0){
                row_flag = true;
                break;
            }
        }
        /*第一列有没有自带的0*/
        for(int i = 0; i < row; i++){
            if(matrix[i][0] == 0){
                col_flag = true;
                break;
            }
        }
        /*将第一行第一列对应位置置0*/
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        /*置零*/
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        /*如果第一行第一列有原生的0，那么就把第一行或第一列全部置零*/
        if(row_flag){
            for(int i = 0; i < col; i++){
                matrix[0][i] = 0;
            }
        }

        if(col_flag){
            for(int i = 0; i < row; i++){
                matrix[i][0] = 0;
            }
        }
    }
};