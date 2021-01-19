#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += nums[i] * (n - i - 1);
    }
    printf("%lld", ans);
    
    return 0;
}