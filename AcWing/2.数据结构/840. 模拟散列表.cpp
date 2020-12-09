#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
const int N = 100010;
int const maxn = 100003;//大于十万的第一个质数

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
    ListNode():val(0), next(nullptr){}
};



int main(){
    vector<ListNode*> HashTable(N);
    
    /*拉链法去重映射冲突*/
    for(int i = 0; i < N; i++) HashTable[i] = new ListNode();
    int n;
    cin >> n;
    while(n--){
        char op[2];
        cin >> op;
        int num;
        cin >> num;
        if(op[0] == 'I'){
            int idx = (num % maxn + maxn) % maxn;//将可能映射为负数的下标变为整数
            ListNode* node = new ListNode(num);
            node -> next = HashTable[idx] -> next;
            HashTable[idx] -> next = node;
        }
        else if(op[0] == 'Q'){
            int idx = (num % maxn + maxn) % maxn;
            ListNode* head = HashTable[idx];
            while(head -> next != nullptr){
                if(head -> next -> val == num){
                    cout<<"Yes"<<endl;
                    break;;
                }
                head = head -> next;
            }
            if(head -> next == nullptr)
                cout<<"No"<<endl;
        }
    }
    return 0;
}