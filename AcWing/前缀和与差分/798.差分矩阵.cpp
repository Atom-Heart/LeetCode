#include <iostream>
#include <vector>
using namespace std;

void insert(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2, int c){
    matrix[x1][y1] += c;
    matrix[x2 + 1][y1] -= c;
    matrix[x1][y2 + 1] -= c;
    matrix[x2 + 1][y2 + 1] += c;
}

int main(){
    int n, m, q;
    cin>>n>>m>>q;
    vector<vector<int>> a(n + 2, vector<int>(m + 2, 0));
    /*在差分矩阵中b[i][j]代表在以(i, j)为左上角的矩阵包含所有数字都加上c*/
    vector<vector<int>> b(n + 2, vector<int>(m + 2, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
        }
    }
    
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            insert(b, i, j, i, j, a[i][j]);
        }
    }
    
    
    for(int i = 0; i < q; i++){
        int x1, x2, y1, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(b, x1, y1, x2, y2, c);
    }
    /*算出差分矩阵的前缀和*/
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}