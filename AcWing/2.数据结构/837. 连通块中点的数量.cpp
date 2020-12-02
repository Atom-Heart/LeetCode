#include<iostream>
using namespace std;

const int N = 100010;
int q[N],Size[N];

int find(int x){
    if(q[x] != x) q[x] = find(q[x]);
    return q[x];
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        q[i] = i;
        Size[i] = 1;
    }
    while(m--){
        int x, y;
        char op[3];
        cin >> op;
        if(op[0] == 'C'){
            cin >> x >> y;
            if(find(x) == find(y)) continue;
            Size[find(x)] += Size[find(y)];
            q[find(y)] = find(x);
        }
        else if(op[1] == '1'){
            cin >> x >> y;
            if(find(q[x]) == find(q[y])) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else{
            cin >> x;
            cout<<Size[find(x)]<<endl;
        }
    }
    return 0;
}