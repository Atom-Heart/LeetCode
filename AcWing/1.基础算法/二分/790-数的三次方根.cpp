#include <iostream>
using namespace std;
int main(){
    double x;
    cin>>x;
    double l = -10000, r = 10000;
    while(r - l > 1e-8){//精确到小数点后六位，那么就判断后8位
        double mid = (l + r) / 2;
        if(mid * mid * mid >= x){
            r = mid;
        }
        else{
            l = mid;//这里不能写成l = mid + 1，因为值可能在10~11之间
        }
    }
    printf("%lf\n", l);
    return 0;
}

作者：CeciliaLiu
链接：https://www.acwing.com/activity/content/code/content/567304/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。