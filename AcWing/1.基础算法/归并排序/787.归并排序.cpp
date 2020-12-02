#include <iostream>
using namespace std;
void merge_sort(int nums[], int l, int r){
    if(l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);

    int arr[r - l + 1];
    int i = l, j = mid + 1, index = 0;;

    while(i <= mid && j <= r){
        if(nums[i] > nums[j]){
            arr[index++] = nums[j++];
        }
        else{
            arr[index++] = nums[i++];
        }
    }

    while(i <= mid){
        arr[index++] = nums[i++];
    }
    while(j <= r){
        arr[index++] = nums[j++];
    }
    for(i = l, j = 0; i <= r; j++, i++){
        nums[i] = arr[j];
    }
}

int main(){
    int n;
    cin>>n;
    int nums[n];
    for(int i = 0; i < n; i++) cin>>nums[i];

    merge_sort(nums, 0, n - 1);

    for(int i = 0; i < n; i++) cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}

作者：CeciliaLiu
链接：https://www.acwing.com/activity/content/code/content/562570/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。