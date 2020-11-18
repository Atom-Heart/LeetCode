#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;




int main(){
    int m, n, q;
    cin >> n >> m >> q;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    /*初始化dp数组,以dp[i][j]为右下角的矩阵和*/
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + matrix[i - 1][j - 1] - dp[i - 1][j - 1];
        }
    }


    int x1, y1, x2, y2;
    for(int i = 0; i < q; i++){
        cin>>x1>>y1>>x2>>y2;
        cout<<dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]<<endl;
    }

    return 0;
}

作者：CeciliaLiu
链接：https://www.acwing.com/activity/content/code/content/577736/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。