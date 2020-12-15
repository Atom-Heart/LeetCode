#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    while(m--){
        int a, b;
        cin >> a >> b;
        if(a == b) continue;
        if(find(adj[a].begin(), adj[a].end(), b)== adj[a].end())
            adj[a].push_back(b);
    }
    /*for(int i = 0; i < adj.size(); i++){
        cout<<"i = "<<i<<" ";
        for(int j = 0; j < adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }*/
    queue<int> q;
    q.push(1);
    int steps = 0;
    bool flag = false;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int node = q.front();
            q.pop();
            vector<int> neighbors = adj[node];
            for(int neighbor : neighbors){
                q.push(neighbor);
                if(neighbor == n){
                    flag = true;
                    break;
                }
            }
        }
        steps++;
        if(flag) break;
    }
    if(flag)
        cout<<steps<<endl;
    else
        cout<<-1<<endl;
    return 0;
}