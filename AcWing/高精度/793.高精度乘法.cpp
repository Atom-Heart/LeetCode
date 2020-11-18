#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> mul(vector<int> &A, int b){
    vector<int> C;
    int t = 0;
    /*当i==A.size()时，t有可能还大于零，说明产生了进位，需要继续push*/
    for(int i = 0; i < A.size() || t; i++){
        if(i < A.size()){
            t += A[i] * b;
        }
        C.push_back(t % 10);
        t /= 10;
    }

    /*去除前导零*/
    while(C.size() > 1 && C.back() == 0){
        C.pop_back();
    }
    return C;
}

int main(){
    string a;
    cin>>a;
    int b;
    cin>>b;

    vector<int> A;
    for(int i = a.size() - 1; i >= 0; i--){
        A.push_back(a[i] - '0');
    }

    vector<int> C;
    C = mul(A, b);

    for(int i = C.size() - 1; i >= 0; i--){
        cout<<C[i];
    }
    return 0;
}

作者：CeciliaLiu
链接：https://www.acwing.com/activity/content/code/content/571499/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。