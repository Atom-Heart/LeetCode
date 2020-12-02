#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp(vector<int>& A, vector<int>& B){
    if(A.size() != B.size()){
        return A.size() > B.size();
    }

    for(int i = A.size() - 1; i >= 0; i--){
        if(A[i] != B[i]){
            return A[i] > B[i];
        }
    }
    return true;

    /*if(A.size() > B.size()) return true;
    else if(A.size() < B.size()) return false;

    for(int i = A.size() - 1; i >= 0; i--){
        if(A[i] < B[i]) return false;
    }
    return true;*/
}

vector<int> sub(vector<int> &A, vector<int> &B){
    vector<int> C;
    for(int i = 0, t = 0; i < A.size(); i++){
        t = A[i] - t;//首先减去借位
        if(i < B.size()){//没有超过B的范围
            t -= B[i];//减去B[i]这一位的数字
        }
        C.push_back((t + 10) % 10);//t的两种情况:1.t >= 0 -> 那么t就是它本身;2.t < 0 -> t = t + 10。这句相当于综合了这两种情况
        if(t < 0) t = 1;
        else t = 0;
    }
    /*去除可能的前导零*/
    while(C.size() > 1 && C.back() == 0){
        C.pop_back();
    }

    return C;
}

int main(){
    string a, b;
    cin>>a>>b;
    vector<int> A, B, C;
    for(int i = a.size() - 1; i >= 0; i--){
        A.push_back(a[i] - '0');
    }
    for(int i = b.size() - 1; i >= 0; i--){
        B.push_back(b[i] - '0');
    }

    if(cmp(A, B)){
        auto c = sub(A, B);
        for(int i = c.size() - 1; i >= 0; i--){
            cout<<c[i];
        }
    }
    else{
        auto c = sub(B, A);
        cout<<'-';
        for(int i = c.size() - 1; i >= 0; i--){
            cout<<c[i];
        }
    }
    return 0;
}

作者：CeciliaLiu
链接：https://www.acwing.com/activity/content/code/content/571426/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。