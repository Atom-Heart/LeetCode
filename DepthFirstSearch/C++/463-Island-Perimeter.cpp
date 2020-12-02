/*方法一：一个点是陆地的话，有效的边长=4-相邻陆地的个数*/
class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int x = 0;
                    for(int k = 0; k < 4; k++){
                        int new_x = i + dx[k];
                        int new_y = j + dy[k];
                        if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n){
                            if(grid[new_x][new_y] == 1) x++;
                        }
                    }
                    ans += (4 - x);
                }
            }
        }
        return ans;
    }
};

/*几何关系*/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int x = 0;//岛屿数量
        int y = 0;//相邻岛屿数量
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    x++;
                    /*之所以只计算上边和右边是因为避免重复计算相邻的个数*/
                    if(i - 1 >= 0 && grid[i - 1][j] == 1) y++;//上边有一个相邻
                    if(j - 1 >= 0 && grid[i][j - 1] == 1) y++;//左边有一个相邻
                }
            }
        }
        return 4 * x - 2 * y;
    }
};