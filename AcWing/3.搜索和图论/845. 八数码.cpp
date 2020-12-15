#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    /*用字符串表示状态*/
    string start;
    char ch[2];
    for(int i = 0; i < 9; i++){
        cin >> ch;
        start += ch[0];
    }
    string end = "12345678x";
    unordered_map<string, int> mp;
    queue<string> st;
    /*起始状态走的步数为0*/
    mp[start] = 0;
    
    st.push(start);
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    while(!st.empty()){
        string state = st.front();
        st.pop();
        if(state == end){
            cout<<mp[state]<<endl;
            return 0;
        }
        int distance = mp[state];
        int idx = state.find('x');
        /*一维下标转换为二维下标*/
        int x = idx / 3, y = idx % 3;
        for(int i = 0; i < 4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x >= 0 && new_x < 3 && new_y >= 0 && new_y < 3){
                /*二维坐标转一维*/
                int x = new_x * 3 + new_y;
                swap(state[x], state[idx]);
                /*该状态没有被访问过,就去访问；如果被访问过，那就不去访问了*/
                if(!mp.count(state)){
                    mp[state] = distance + 1;
                    st.push(state);
                }
                /*状态还原*/
                swap(state[x], state[idx]);
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}