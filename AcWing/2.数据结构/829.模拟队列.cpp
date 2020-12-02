#include<iostream>
#include<string>
using namespace std;
const int N = 100010;
int arr[N], top = 0, cur = 0;
int main(){
    int m;
    cin >> m;
    while(m--){
        string op;
        cin >> op;
        if(op == "push"){
            int x;
            cin >> x;
            arr[cur++] = x;
        }
        else if(op == "pop"){
            top++;
        }
        else if(op == "empty"){
            if(top == cur) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else if(op == "query"){
            cout<<arr[top]<<endl;
        }
    }
    return 0;
}