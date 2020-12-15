#include<iostream>
#include<vector>
using namespace std;

vector<int> route;
void backTracking(int level , vector<bool>& used, int n){
    if(level == n){
        for(int num : route){
            cout<<num<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(used[i]) continue;
        used[i] = true;
        route.push_back(i);
        backTracking(level + 1, used, n);
        route.pop_back();
        used[i] = false;
    }
}

int main(){
    int n;
    cin >> n;
    vector<bool> used(n + 1, false);
    backTracking(0, used, n);
    return 0;
}