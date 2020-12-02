#include <iostream>
#include <vector>
using namespace std;
const int N = 100010;
int nums[N];
int left_bound(int l, int r, int target){
    int left = l, right = r;
    while(left < right){
        int mid = (left + right) >> 1;
        if(target == nums[mid]){
            if(mid == 0 || (nums[mid - 1] < nums[mid])){
                return mid;
            }
            right = mid;
        }
        else if(target < nums[mid]){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;
}

int right_bound(int l, int r, int target){
    int left = l, right = r;
    while(left < right){
        int mid = (left + right) >> 1;
        if(target == nums[mid]){
            if(mid == r - 1 || (nums[mid + 1] > nums[mid])){
                return mid;
            }
            left = mid + 1;
        }
        else if(target < nums[mid]){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    int n, q;
    cin>>n>>q;
    for(int i = 0; i < n; i++) cin>>nums[i];
    for(int i = 0; i < q; i++){
        int target;
        cin>>target;
        cout << left_bound(0, n, target) <<" " << right_bound(0, n, target)<<endl;
    }
    return 0;
}

作者：CeciliaLiu
链接：https://www.acwing.com/activity/content/code/content/566981/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。