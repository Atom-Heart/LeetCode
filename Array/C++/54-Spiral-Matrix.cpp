class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return {};
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        vector<int> ans;
        while(1){
            /*左到右*/
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[up][i]);
            }
            if(++up > down) break;
            /*上到下*/
            for(int i = up; i <= down; i++){
                ans.push_back(matrix[i][right]);
            }
            if(--right < left) break;
            /*右到左*/
            for(int i = right; i >= left; i--){
                ans.push_back(matrix[down][i]);
            }
            if(--down < up) break;
            /*下到上*/
            for(int i = down; i >= up; i--){
                ans.push_back(matrix[i][left]);
            }
            if(++left > right) break;
        }
        return ans;
    }
};