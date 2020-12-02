#include<iostream>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
int ne[N];
char s[M], p[N];

int main(){
    /*s和p的下标都是从1开始的，这样写出的代码比较好懂*/
    cin >> n >> p + 1 >> m >> s + 1;
    /*i从2开始遍历是因为next[1]一定等于0，因为p[1~1]只有一个字母，没有相等的前缀和后缀*/
    /*next数组的计算就是用p的前缀去和p去做匹配*/
    for(int i = 2, j = 0; i <= n; i++){
        while(j != 0 && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) j++;
        /*每次遍历都会得到一个next[i]的值，这个值最小为0*/
        /*这里我认为还是很抽象的*/
        ne[i] = j;
    }
    
    for(int i = 1, j = 0; i <= m; i++){
        /*每次试图进行匹配的是s[i]和p[j + 1]，如果s[i] != p[j + 1]，需要把j前移最小的距离，如果已经把j移动到0，说明j退无可退*/
        /*
        为什么要去匹配s[i]和p[j + 1]? 因为next[i] = j代表p[1~j] 等于 p[i - j + 1, i]，一旦发现s[i] != p[j + 1]，可以使用next[j]
        回退到最大匹配的前缀的位置，然后可以直接再判断s[i]是否等于p[j + 1]
        */
        while(j != 0 && s[i] != p[j + 1]) j = ne[j];
        /*如果等于,相当于做j++,i++*/
        if(s[i] == p[j + 1]) j++;
        /*j已经到了模式串的最后一个位置，说明匹配完了*/
        if(j == n){
            /*输出对应的起始下标*/
            printf("%d ", i - n);
            /*然后再去看有没有其他能匹配的位置*/
            j = ne[j];
        }
    }
    return 0;
}