/*DFS思想：获得所有以1,2,3...0开头的数，然后这些数再继续append 0,1,2..9，直到这个数字大于n。整个过程是以先序的顺序DFS进行*/
class Solution {
public:
    vector<int> ans;
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i <= 9; i++){
            DFS(i, n);
        }
        return ans;
    }
    void DFS(int begin, int n){
        if(begin > n) return;
        ans.push_back(begin);
        for(int i = 0; i <= 9; i++){
            int next = begin * 10 + i;
            DFS(next, n);
        }
    }
};