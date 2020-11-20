/*贪心：自己写的*/
/*我的思路是如果两个区间相交，尽量去选择那个覆盖区间较短的区间*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        if(intervals.size() == 0 || intervals.size() == 1) return 0;
        sort(intervals.begin(), intervals.end());
        int j = 1;
        for(int i = 0; i < intervals.size();){
            int left = intervals[i][0];
            int right = intervals[i][1];
            j = i + 1;
            while(j < intervals.size() && intervals[j][0] < right){
                if(intervals[j][1] > right){
                    j++;//删除下一个区间
                    ans++;
                }
                else{
                    ans++;//删除当前区间
                    break;
                }
            }
            i = j;
        }
        return ans;
    }
};
/*贪心：先算出最多有多少不重复区间，然后用原区间数减去不重复区间数就是需要移除的最小数量*/
class Solution {
public:
    /*struct cmp{
        bool operator()(vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        }
    };*/
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0 || intervals.size() == 1) return 0;
        sort(intervals.begin(), intervals.end(), cmp);//按右区间升序排序
        int count = 1;//不重复区间最少有一个
        int right = intervals[0][1];
        for(auto interval : intervals){
            int left = interval[0];
            if(left >= right){//如果下一个区间的左边界大于之前区间的有边界，说明这两个区间不重复
                right = interval[1];//更新右边界
                count++;
            }
        }
        return intervals.size() - count;
    }
};