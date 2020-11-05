/*最小堆+贪心*/
/*梯子相当于有无限块砖，所以我需要把好钢用在刀刃上，用梯子去过高度差最大的部分->贪心思想;那么就需要找出到当前为止尽可能大的楼间距（不能直接去找最大的楼间距，因为你可能都到不了后面）->最小堆*/
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>, greater<int>> pq;
        int n = heights.size();
        int need = 0;//需要用的砖块数
        for(int i = 1; i < n; i++){
            int diff = heights[i] - heights[i - 1];
            if(diff > 0){
                pq.push(diff);
                if(pq.size() > ladders){
                    need += pq.top();//把较小的高度差用砖弥补
                    pq.pop();
                }
                if(need > bricks){//砖头不够用了
                    return i - 1;
                }
            }
        }
        return n - 1;
    }
};