#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    vector<int> ans;
    while(m--){
        int a, b;
        cin >> a >> b;
        indegree[b]++;
        adj[a].push_back(b);
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int i = 0; i < adj[node].size(); i++){
            indegree[adj[node][i]]--;
            if(indegree[adj[node][i]] == 0){
                q.push(adj[node][i]);
            }
        }
    }
    if(ans.size() == n)
        for(auto num : ans){
            cout<<num<<" ";
        }
    else cout<<"-1"<<endl;
    return 0;
}