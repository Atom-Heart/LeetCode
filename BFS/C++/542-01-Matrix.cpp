





/*方法一：把1当作源点做层次BFS，每一层遍历完steps++，直到某一层遍历到0。Debug不出来，而且代码写的非常冗余*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size(); 
        vector<vector<int>> ans(M, vector<int>(N, 0));
        vector<pair<int, int>> items;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(matrix[i][j] == 1) items.push_back(make_pair(i, j));
            }
        }
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        for(auto item : items){
            queue<pair<int, int>> q;
            q.push(item);
            int steps = 0;
            vector<vector<bool>> used(M, vector<bool>(N, false));
            bool flag = false;//退出标志
            while(!q.empty()){
                int sz = q.size();
                while(sz--){
                    auto temp = q.front();
                    q.pop();
                    int x = temp.first, y = temp.second;
                    for(int i = 0; i < 4; i++){
                        int new_x = x + dx[i];
                        int new_y = y + dy[i];
                        if(new_x >= 0 && new_x < M && new_y >= 0 && new_y < N && used[new_x][new_y] == false){
                            used[new_x][new_y] = true;
                            if(matrix[new_x][new_y] == 1){
                                q.push(make_pair(new_x, new_y));
                            }
                            else{
                                flag = true;
                                break;
                            }
                        }
                    }
                    steps++;
                    if(flag) break;
                }
                if(flag) break;
            }
            ans[item.first][item.second] = steps;
        }
        return ans;
    }
};

/*
*思路：每个元素到最近的0的距离（哈夫曼距离，只能向上下左右四个方向走的距离），可以想到这是一个最短路径问题，思考能不能用最短路径
*算法来处理这个问题，根据经验，权值为1的最短路径问题可以使用BFS解决。
*   这个题让我求的是每个元素最近到0的距离，那第一感觉就是从每个1开始搜索0,但也可以反向思考，从1搜索0和从0搜索1得到的距离是一样的，可以将0作为源点去搜索1
*/

class Solution {
public:
    vector<int> dx = {-1, 1, 0 ,0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1) matrix[i][j] = -1;//标记(i, j)位置的1是没有被访问过的
                else q.push(make_pair(i, j));//把0的坐标入队
            }
        }
        
        while(!q.empty()){
            auto item = q.front();
            q.pop();
            int x = item.first;
            int y = item.second;
            for(int i = 0; i < 4; i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && matrix[new_x][new_y] == -1){
                    matrix[new_x][new_y] = matrix[x][y] + 1;
                    q.push(make_pair(new_x, new_y));//把访问过的1继续当作源点进行扩散
                }
            }
        }
        return matrix;
    }
};