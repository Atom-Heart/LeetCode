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
        ans += abs(nums[i] - nums[n / 2]);
    }
    cout<<ans<<endl;
    return 0;
}