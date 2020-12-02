#include<iostream>
#include<stack>
using namespace std;

const int N = 100010;
int arr[N];

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) cin>>arr[i];
    
    stack<int> st;
    
    for(int i = 0; i < n; i++){
        if(st.size() == 0){
            st.push(arr[i]);
            cout<<"-1 ";
        }
        else{
            while(!st.empty() && arr[i] <= st.top()){
                st.pop();
            }
            if(st.empty()){
                cout<<"-1 ";
            }
            else{
                cout<<st.top()<<" ";
            }
            st.push(arr[i]);
        }
    }
    
    return 0;
}