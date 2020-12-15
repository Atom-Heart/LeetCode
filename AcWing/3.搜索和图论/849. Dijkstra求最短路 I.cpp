#include<iostream>
#include<algorithm>
#include<limits.h>
#include<cstring>
#include<vector>
using namespace std;

const int N = 510;
int n, m;
int adj[N][N];
int dist[N];
bool st[N];


int dijkstra(){
    /*初始化距离数组*/
    //for(int i = 1; i <= n; i++) dist[i] = INT_MAX;  
    memset(dist, 0x3f,sizeof dist);     //初始化距离  0x3f3f3f3f代表无限大(只是足够大，但不等于INT_MAX)
                                        //memset是按照字节进行初始化的
                                        
    /*1号节点是起点，距离自身的距离为0*/
    dist[1] = 0;
    /*每次迭代都找到还没有确定距离且距离1号点的距离最短的那个点*/
    for(int i = 0; i < n; i++){
        int t = -1;//这就是上面说的那个点
        for(int j = 1; j <= n; j++){
            if(!st[j] && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        st[t] = true;//表示这个点的距离确定了
        /*表示用这个确定的点去更新其他点*/
        for(int j = 1; j <= n; j++){
            dist[j] = min(dist[j], dist[t] + adj[t][j]);//这里会越界
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main(){

    cin >> n >> m;
    /*初始化临界矩阵*/
    /*for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            adj[i][j] = INT_MAX;//可能会产生加法越界
        }
    }*/
    memset(adj,0x3f,sizeof adj);
    
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        /*可能会有重边，选择一条权值最小的边*/
        adj[a][b] = min(adj[a][b], c);
        
    }
    cout<<dijkstra()<<endl;
    
    return 0;
}