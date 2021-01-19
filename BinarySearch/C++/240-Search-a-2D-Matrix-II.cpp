class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        int i = 0, j = n - 1;
        while(i < m && j >= 0){
            int cur = matrix[i][j];
            if(target == cur) return true;
            else if(cur > target) j--;
            else i++;
        }
        return false;
    }
};