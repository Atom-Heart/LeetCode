#include<iostream>
#include<string>
using namespace std;
const int N = 100010;
int arr[N], top = 0;

int main(){
    int m;
    cin>>m;
    while(m--){
        string op;
        cin>>op;
        if(op == "push"){
            int x;
            cin >> x;
            arr[top++] = x;
        }
        else if(op == "pop"){
            top--;
        }
        else if(op == "empty"){
            if(top == 0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else if(op == "query"){
            cout<<arr[top - 1]<<endl;
        }
    }
    return 0;
}