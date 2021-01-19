#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> range;
    while(n--){
        int x, y;
        cin >> x >> y;
        range.push_back(make_pair(x, y));
    }
    
    sort(range.begin(), range.end(), cmp);
    
    
    int ans = 1, end = range[0].second;
    for(int i = 1; i < range.size(); i++){
        if(range[i].first > end){
            ans++;
            end = range[i].second;
        }
    }
    cout<<ans<<endl;
    return 0;
}