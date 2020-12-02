#include<iostream>
#include<stdio.h>
using namespace std;
const int N = 100010;
int p[N];//保存的是每个结点的父节点

int find(int num){
    /*如果编号为num的结点的父节点编号不是自己，那么就递归寻找该节点的祖宗结点，然后将该节点的父节点置为找到的祖宗结点*/
    if(p[num] != num) p[num] = find(p[num]);
    return p[num];
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) p[i] = i;
    while(m--){
        int num1, num2;
        char op[2];
        scanf("%s%d%d", op, &num1, &num2);
        if(op[0] == 'M'){
            p[find(num1)] = find(num2); 
        }
        else{
            if(find(num1) == find(num2)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}