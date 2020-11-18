#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> add(vector<int>& A, vector<int>& B){
    vector<int> C;

    int t = 0;
    for(int i = 0; i < A.size() || i < B.size();i++){
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    /*vector方便给最后一位添加进位*/
    if(t) C.push_back(1);
    return C;
}

int main(){
    string a, b;
    vector<int> A, B;
    cin>>a>>b;
    /*A[0]存的是各位，A[1]是十位...以此类推*/
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    auto c = add(A, B);
    /*需要倒序输出*/
    for(int i = c.size() - 1; i >= 0; i--){
        cout<<c[i];
    }
    return 0;
}

作者：CeciliaLiu
链接：https://www.acwing.com/activity/content/code/content/569449/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。