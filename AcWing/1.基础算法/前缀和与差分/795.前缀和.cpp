#include <iostream>
using namespace std;



int main(){
    int m, n;
    cin>>m>>n;
    int nums[m];
    for(int i = 1; i <= m; i++) cin>>nums[i];
    int pre_sum[m + 1];
    pre_sum[0] = 0;
    for(int i = 1; i <= m; i++){
        pre_sum[i] = pre_sum[i - 1] + nums[i];
    }


    while(n--){
        int left, right;
        cin>>left>>right;
        int sum = pre_sum[right] - pre_sum[left - 1];
        cout<<sum<<endl;
    }
    return 0;
}

作者：CeciliaLiu
链接：https://www.acwing.com/activity/content/code/content/575944/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。