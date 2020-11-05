class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }
    
    void addNum(int x) {
        /*首先确认x是不是已经被包含在某个区间里了，如果在，则不用插入了*/
        if(L.size()){
            /*返回在L中key大于等于x的迭代器，如果不存在，则返回L.end()以表示该key代表的映射不存在;it->first就是包含x的区间的右边界*/
            auto it = L.lower_bound(x);
            if(it != L.end() && it -> second <= x){//it->second就是包含x区间的左边界
                return;//说明it->second <= x <= it -> first
            }
        }
        /*left和right是两个标志，分别表示x是不是和左边的某个区间相邻，x是不是和右边某个区间相邻*/
        int left = L.count(x - 1), right = R.count(x + 1);

        /*左右两边都有相邻的区间，将[left, x - 1], x, [x + 1, right]合并成一个*/
        if(left && right){
            R[L[x - 1]] = R[x + 1];
            L[R[x + 1]] = L[x - 1];
            L.erase(x - 1);
            R.erase(x + 1);
        }
        /*只有左边有相邻区间*/
        else if(left){
            R[L[x - 1]] = x;
            L[x] = L[x - 1];
            L.erase(x - 1);
        }
        /*只有右边有相邻区间*/
        else if(right){
            L[R[x + 1]] = x;
            R[x] = R[x + 1];
            R.erase(x + 1);
        }
        else{
            R[x] = L[x] = x;
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto item : R) ans.push_back({item.first, item.second});
        return ans;

    }
private:
    /*对于[1,2],有L[2] = 1,R[1] = 2*/
    map<int, int> L, R;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */