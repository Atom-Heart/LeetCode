#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 100010;

int n, m;
int h[N], ph[N], hp[N], sz;

/*传入的参数是位置*/
void heap_swap(int a, int b){
    /*hp[i]是i这个位置的数是第几个插入的*/
    /*ph[i]保存的,第i个插入的数在哪个位置*/
    swap(ph[hp[a]], ph[hp[b]]);
    
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u){
    int t = u;//保存最小的数的下标
    /*左儿子存在&&左儿子的值小于h[t]的值*/
    if(u * 2 <= sz && h[u * 2] < h[t]) t = u * 2;
    /*右儿子存在&&右儿子的值小于h[t]的值*/
    if(u * 2 + 1 <= sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    /*说明父节点不是最小结点*/
    if(u != t){
        heap_swap(u, t);
        /*递归下移*/
        down(t);
    }
}

void up(int u){
    /*不是堆顶元素 && 孩子元素比父结点元素要大*/
    while(u / 2 && h[u / 2] > h[u]){
        heap_swap(u / 2, u);
        u /= 2;
    }
}

int main(){
    int n, m = 0;
    cin >> n;
    while(n--){
        char op[10];
        int k, x;
        
        cin >> op;
        /*插入一个数*/
        if(!strcmp(op, "I")){
            cin >> x;
            sz++;
            m++;
            /*建立映射*/
            ph[m] = sz;//第m个插入的数在第sz个位置上
            hp[sz] = m;//sz位置上的数是第m个插入的
            h[sz] = x;
            up(sz);
        }
        /*输出最小值*/
        else if(!strcmp(op, "PM")) cout<<h[1]<<endl;
        /*删除最小值*/
        else if(!strcmp(op, "DM")){
            heap_swap(1, sz);
            sz--;
            down(1);
        }
        /*删除第k个数*/
        else if(!strcmp(op, "D")){
            cin >> k;
            k = ph[k];
            heap_swap(k, sz);
            sz--;
            /*down一下保证k这个位置以下是合法的，up保证k以上是合法的*/
            down(k), up(k);
        }
        /*修改第k个插入的数*/
        else{
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
    return 0;
}