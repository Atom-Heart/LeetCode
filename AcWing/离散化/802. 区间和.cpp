#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 300010
int a[N];
int s[N];

vector<pair<int, int>> add;//待插入的下标和数字
vector<pair<int, int>> query;//待查询的范围
vector<int> all;//待离散化的下标

int find(int x){
    int l = 0, r = all.size();
    while(l < r){
        int mid = (l + r) >> 1;
        if(all[mid] < x) l = mid + 1;
        else r = mid;
    }
    return r + 1;//返回r + 1是想映射到下标从1开始的a[]的位置上，方便前缀和的计算
}

/*去重数组中的重复元素，双指针经典题目*/
vector<int>::iterator unique(vector<int>& nums){
    int j = 0;
    for(int i = 0; i < nums.size(); i++){
        if(i == 0 || nums[i] != nums[i - 1]){
            nums[j] = nums[i];
            j++;
        }
    }
    return nums.begin() + j;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        all.push_back(x);
    }
    
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        query.push_back({l ,r});
        all.push_back(l);
        all.push_back(r);
    }
	/*排序+去重*/
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    
	/*把原离散下标映射到a[]中的连续下标上，all中保存的是原下标，然后在all中利用二分找原下标，返回保存原下标的下标，这样就将原本离散的下标映射到了连续的下标上。a[]有效的区间和all的有效区间是一样的*/
    for(auto item : add){
        int x = find(item.first);
        a[x] += item.second;//在映射过的位置上加上数字
    }
    
    //预处理前缀和
    for(int i = 1; i <= all.size(); i++) s[i] = s[i - 1] + a[i];
    
    for(auto item : query){
		/*求的是映射后的区间*/
        int l = find(item.first), r = find(item.second);
        cout<<s[r] - s[l - 1]<<endl;
    }
    
    return 0;
}