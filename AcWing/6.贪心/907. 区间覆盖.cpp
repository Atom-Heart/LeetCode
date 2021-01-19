#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.first > b.first;
}

int main(){
    int start, end;
    cin >> start >> end;
    int n;
    cin >> n;
    
    vector<pair<int, int>> range;
    while(n--){
        int x, y;
        cin >> x >> y;
        range.push_back(make_pair(x, y));
    }
    
    sort(range.begin(), range.end());
    n = range.size();
    int ans = 0;
    bool flag = false;
    for(int i = 0; i < n; i++){
        int j = i, r = -2e9;
        while(j < n && range[j].first <= start){
            r = max(range[j].second, r);
            j++;
        }
        if(r < start){
            ans = -1;
            break;
        }
        ans++;
        if(r >= end){
            flag = true;
            break;
        }
        start = r;
        i = j - 1;
    }
    if(flag) cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}