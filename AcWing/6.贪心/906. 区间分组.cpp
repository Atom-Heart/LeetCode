#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;



bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    return a.first < b.first;
}
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> range;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(n--){
        int x, y;
        cin >> x >> y;
        auto item = make_pair(x, y);
        range.push_back(item);
    }
    //将左边按左端点从小到大排序
    sort(range.begin(), range.end(), cmp);
    
    for(int i = 0; i < range.size(); i++){
        auto item = range[i];
        if(pq.empty() || pq.top() >= item.first){
            pq.push(item.second);
        }
        else{
            int t = pq.top();
            pq.pop();
            pq.push(item.second);
        }
    }
    cout<<pq.size()<<endl;
    

}