/*找几何规律的题，一开始自己想了一会儿，想不出来*/
/*记住这个方法：先按中心线互换响应位置的元素，再按正对角线交换两边的元素（这两个操作的顺序不影响最终结果，即可以先按正对角线交换，再按中心线交换）*/
/*这是顺时针旋转90°，如果要逆时针旋转90°，那就按逆对角线交换*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++){
            for(int j = 0; j < matrix[i].size(); j++){
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < matrix[i].size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};