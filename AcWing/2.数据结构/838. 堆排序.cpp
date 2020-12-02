#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;

int n, m;
int h[N], size;

void down(int u){
    int t = u;//保存最小的数的下标
    /*左儿子存在&&左儿子的值小于h[t]的值*/
    if(u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
    /*右儿子存在&&右儿子的值小于h[t]的值*/
    if(u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    /*说明父节点不是最小结点*/
    if(u != t){
        swap(h[u], h[t]);
        /*递归下移*/
        down(t);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> h[i];
    size = n;
    
    /*把前一半的结点做下移操作，就可以建立一个小根堆*/
    for(int i = n / 2; i; i--) down(i);
    while(m--){
        cout<<h[1]<<endl;
        /*删除堆顶元素,将最后一个元素覆盖堆顶元素，然后在下移堆顶元素到合适位置*/
        h[1] = h[size];
        size--
        down(1);
    }
    return 0;
}