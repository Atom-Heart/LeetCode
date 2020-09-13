class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int up = 0;
        int down = n - 1;
        int left = 0;
        int right = n - 1;

        int num = 1;

        while(1){
            for(int i = left; i <= right; i++){
                ans[up][i] = num;
                num++;
            }
            if(++up > down) break;

            for(int i = up; i <= down; i++){
                ans[i][right] = num;
                num++;
            }
            if(--right < left) break;

            for(int i = right; i >= left; i--){
                ans[down][i] = num;
                num++;
            }
            if(--down < up) break;

            for(int i = down; i >= up; i--){
                ans[i][left] = num;
                num++;
            }
            if(++left > right) break;
        }
        return ans;
    }
};