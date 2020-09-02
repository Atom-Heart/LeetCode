/*方法一：两次二分*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size();
        int n = matrix[0].size();

        int L = 0;//行的左边界
        int R = m - 1;//行的右边界
        while(L < R){//先找到目标值所在的那一行7
            int mid = (L + R) / 2;//取行数的中间值
            /********这一部分我第一次写不出来********/
            if(matrix[mid][n - 1] == target){
                return true;
            }
            else if(matrix[mid][n - 1] > target){
                R = mid;
            }
            else{
                L = mid + 1;
            }
        }
        if(L > m - 1){//处理target比矩阵中所有数都大的情况
            return false;
        }
        /******************************************/

        int L_2 = 0;
        int R_2 = n - 1;
        while(L_2 <= R_2){
            int mid_2 = (L_2 + R_2) / 2;
            if(matrix[L][mid_2] == target){
                return true;
            }
            else if(matrix[L][mid_2] > target){
                R_2 = mid_2 - 1;
            }
            else{
                L_2 = mid_2 + 1;
            }
        }
        return false;
    }
    
};
/*方法二：右上角扩散法*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n - 1;

        while(row < m && col >= 0){//向左斜下方移动搜索
            /*从矩阵的右上角开始匹配，如果匹配到了，返回true*/
            if(matrix[row][col] == target) return true;
            /*target比这一行最大的数还大，说明在下一行*/
            else if(matrix[row][col] < target){
                row++;
            }
            /*该位置元素比target大，说明这一列（从当前行到最后一行）都比target大*/
            else{
                col--;
            }
        }
        return false;
        
    }
};