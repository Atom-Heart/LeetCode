/*自己写的双指针，很恶心*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){return a[0] < b[0] || a[0] == b[0] && a[1] < b[1];});
        int index = 0;
        while(index < intervals.size()){
            int left = intervals[index][0];
            int right = intervals[index][1];
            if(index == intervals.size() - 1){//如果是最后一个区间，而且这个区间是另立门户的
                ans.push_back({left, right});
                break;
            }
            else{//现在这个区间绝对不是最后一个区间
                while(index < intervals.size()){
                    if(index == intervals.size() - 1){
                        ans.push_back({left, right});
                        break;
                    }
                    int next_left = intervals[index + 1][0];//获取下一个区间的left
                    if(next_left <= right){//区间可以合并
                        index++;//进入到下一个区间
                        right = max(right, intervals[index][1]);//right值更新为最大的右区间
                    }
                    else{//区间不能合并
                        ans.push_back({left, right});
                        break;
                    }
                }
                index++;
            }
            
        }
        return ans;
    }
};

/*优化后的双指针写法*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        for(int i = 0; i < intervals.size();){
            int left = intervals[i][0];
            int right = intervals[i][1];
            
            int j = i + 1;//选择下一个区间
            while(j < intervals.size() && intervals[j][0] <= right){//下一个区间不能越界
                if(right < intervals[j][1]){//合并
                    right = intervals[j][1];
                }
                j++;
            }
            ans.push_back({left, right});
            i = j;
        }
        return ans;
    }
};