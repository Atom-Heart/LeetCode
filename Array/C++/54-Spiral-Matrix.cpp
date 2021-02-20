class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return {};
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        vector<vector<bool>> used(m, vector<bool>(n, false));

        for(int i = 0, d = 0, x = 0, y = 0; i < m * n; i++){
            ans.push_back(matrix[x][y]);    
            used[x][y] = true;

            int a = x + dx[d];
            int b = y + dy[d];
            
            if(a < 0 || a >= m || b < 0 || b >= n || used[a][b]){
                d = (d + 1) % 4;
                a = x + dx[d];
                b = y + dy[d];
            }
            x = a;
            y = b;
        }
        return ans;
    }
};