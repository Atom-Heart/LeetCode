/*方法一：减治法*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int row = m - 1;
        int col = 0;
        while(row >= 0 && col < n){
            if(matrix[row][col] == target){
                return true;
            }
            /*这一行的后面的列都大于target，剪掉*/
            else if(matrix[row][col] > target){
                row--;
            }
            /*这一列上面的所有行都小于target，剪掉*/
            else{
                col++;
            }
        }
        return false;
    }
};
https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/er-fen-fa-pai-chu-fa-python-dai-ma-java-dai-ma-by-/