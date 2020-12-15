#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>

using namespace std;
typedef pair<int, int> PII;

const int N = 100010;
vector<vector<PII>> gra;
int dist[N];
int st[N];
int n, m;

int solve(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});//first存储距离，second存储节点编号
    
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        int node = t.second;
        int distance = t.first;
        if(st[node]) continue;
        st[node] = true;
        
        for(int i = 0; i < gra[node].size(); i++){
            int new_node = gra[node][i].first;
            int len = gra[node][i].second;
            if(dist[new_node] > dist[node] + len){
                dist[new_node] = dist[node] + len;
                heap.push({dist[new_node], new_node});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    scanf("%d %d", &n, &m);
    gra.resize(n + 1);
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        gra[a].push_back({b, c});
    }
    cout<<solve()<<endl;
    return 0;
}