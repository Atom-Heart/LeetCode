/*
所谓差分，就是维护一个差分数组，差分数组中每个位置的值等于原数组当前位置的值减去前一个位置的值nums[i] - nums[i - 1].
差分数组的前缀和就是原数组。差分相等于前缀和的逆运算。
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++) cin>>nums[i];
    
    /*创建并初始化差分数组*/
    vector<int> a(n + 1, 0);//n + 1是为了防止越界
    a[0] = nums[0];
    for(int i = 1; i < n; i++) a[i] = nums[i] - nums[i - 1];
    
    for(int i = 0; i < m; i++){
        int l, r, c;
        cin>>l>>r>>c;
        /*相当于给nums[l] ~ nums[n - 1]都加了c*/
        /*注意，l和r是从1开始的，对应到下标应该减1*/
        a[(l - 1)] += c;
        /*相当于给nums[r + 1] ~ nums[n - 1]都减了c*/
        a[(r - 1) + 1] -= c;
        
    }
    
    for(int i = 1; i < n; i++) a[i] += a[i - 1];
    for(int i = 0; i < n; i++) cout<<a[i]<<" ";
    return 0;
}