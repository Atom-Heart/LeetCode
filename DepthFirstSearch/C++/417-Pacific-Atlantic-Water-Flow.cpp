/*正向DFS*/
class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        /*是否能流到太平洋*/
        vector<vector<bool>> A(m, vector<bool>(n, false));
        /*是否能流到大西洋*/
        vector<vector<bool>> B(m, vector<bool>(n, false));

        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                vector<vector<bool>> used1(m, vector<bool>(n, false));
                dfs1(i, j, matrix, A, used1);
                vector<vector<bool>> used2(m, vector<bool>(n, false));
                dfs2(i, j, matrix, B, used2);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(B[i][j] == false) cout<<"false ";
                else cout<<"true ";
            }
            cout<<endl;
        }

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(A[i][j] && B[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    bool dfs1(int x, int y, vector<vector<int>> matrix, vector<vector<bool>>& A, vector<vector<bool>>& used){
        int m = matrix.size();
        int n = matrix[0].size();
        if(x == 0 || y == 0){
            A[x][y] = true;
            return true;
        }
        else if(A[x][y] == true){
            return true;
        }
        for(int i = 0; i < 4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && used[new_x][new_y] == false && matrix[new_x][new_y] <= matrix[x][y]){
                used[new_x][new_y] = true;
                if(dfs1(new_x, new_y, matrix, A, used)){
                    A[x][y] = true;
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs2(int x, int y, vector<vector<int>> matrix, vector<vector<bool>>& A, vector<vector<bool>>& used){
        int m = matrix.size();
        int n = matrix[0].size();
        if(x == m - 1 || y == n - 1){
            A[x][y] = true;
            return true;
        }
        else if(A[x][y] == true){
            return true;
        }
        for(int i = 0; i < 4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && used[new_x][new_y] == false && matrix[new_x][new_y] <= matrix[x][y]){
                used[new_x][new_y] = true;
                if(dfs2(new_x, new_y, matrix, A, used)){
                    A[x][y] = true;
                    return true;
                }
            }
        }
        return false;
    }
};

/*反向DFS*/
class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> matrix;
    bool isVaild(int x, int y, vector<vector<bool>>& A){
        int m = matrix.size();
        int n = matrix[0].size();
        if(x < 0 || x >= m || y < 0 || y >= n || A[x][y] == true) return false;
        return true;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix1) {
        if(matrix1.size() == 0) return {};
        matrix = matrix1;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ans;
        
        vector<vector<bool>> A(m, vector<bool>(n, false));
        vector<vector<bool>> B(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            dfs(i, 0, A);
            dfs(i, n - 1, B);
        }
        for(int i = 0; i < n; i++){
            dfs(0, i, A);
            dfs(m - 1, i, B);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(A[i][j] && B[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
    
    void dfs(int x, int y, vector<vector<bool>>& A){
        A[x][y] = true;
        for(int i = 0; i < 4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(isVaild(new_x, new_y, A) && matrix[x][y] <= matrix[new_x][new_y]){
                dfs(new_x, new_y, A);
            }
        }
    }

};