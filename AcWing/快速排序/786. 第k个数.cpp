#include <iostream>
using namespace std;
int quick_sort(int nums[], int l, int r, int k){
    if(l == r) return nums[l];
    int x = nums[(l + r) >> 1];
    int i = l - 1, j = r + 1;
    while(i < j){
        do{i++;}while(nums[i] < x);
        do{j--;}while(nums[j] > x);
        if(i < j){
            swap(nums[i], nums[j]);
        }
    }
    int len = j - l + 1;
    if(k <= len) return quick_sort(nums, l, j, k);
    return quick_sort(nums, j + 1, r, k - len);
}


int main(){
    int n, k;
    cin>>n;
    cin>>k;
    int nums[n];
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    cout<<quick_sort(nums, 0, n - 1, k)<<endl;
    return 0;
}

作者：CeciliaLiu
链接：https://www.acwing.com/activity/content/code/content/562475/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。