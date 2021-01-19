class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*枚举所有起点*/
        int n = gas.size();
        for(int i = 0; i < n;){
            /*枚举所有步数*/
            int j = 0, left = 0;
            for(; j < n; j++){
                int next = (i + j) % n;
                left += (gas[next] - cost[next]);
                if(left < 0) break;
            }
            if(j == n) return i;
            i = i + j + 1;
        }
        return -1;
    }
};