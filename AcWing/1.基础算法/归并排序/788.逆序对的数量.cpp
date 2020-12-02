#include <iostream>
using namespace std;
const int N = 100010;

long long merge_sort(int nums[], int l, int r){
        if(l >= r) return 0;
        int mid = (l + r) >> 1;

        long long res = merge_sort(nums, l, mid) + merge_sort(nums, mid + 1, r);

        int temp[N];

        int i = l, j = mid + 1, k = 0;
        while(i <= mid && j <= r){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            } 
            else{
                temp[k++] = nums[j++];
                /*这里计算nums[j]这个数有几个逆序对*/
                res += (mid - i + 1);

            }
        }

        while(i <= mid) temp[k++] = nums[i++];
        while(j <= r) temp[k++] = nums[j++];

        for(i = 0, j = l; j <= r; i++, j++){
            nums[j] = temp[i];
        }
        return res;
    }

int main(){
    int n;
    cin >> n;
    int nums[n];
    for(int i = 0; i < n; i++) cin>>nums[i];
    cout<<merge_sort(nums, 0, n - 1);
    return 0;
}

作者：CeciliaLiu
链接：https://www.acwing.com/activity/content/code/content/564821/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。