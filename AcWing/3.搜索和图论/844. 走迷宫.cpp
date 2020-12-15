//宽搜用队列
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
const int N = 110;
using namespace std;
typedef pair<int, int> PII;
int n, m;
int g[N][N], d[N][N];
int bfs()
{
    queue<PII> q;
    memset(d, -1, sizeof d);
    d[0][0] = 0;
    q.push({0, 0});
    
    int dx[4] = {-1, 1, 0 , 0}, dy[4] = {0, 0, -1, 1};
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i ++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >=0 && x < n && y >= 0 && y < m && d[x][y] == -1 && g[x][y] == 0)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }
    return d[n - 1][m - 1];
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++) cin >> g[i][j];
    }
    cout << bfs() << endl;
    return 0;
}