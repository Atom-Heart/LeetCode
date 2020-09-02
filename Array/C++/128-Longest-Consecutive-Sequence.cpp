class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans = 0;
        for(int num : nums){
            s.insert(num);
        }

        /*复杂度分析*/
        /*如果数组中元素是全都不重复的，并且我们认为set的插入和查找都是O(1)的，整体应该就是O(N),因为只有在遇到起始序列的时候才会遍历整个序列，遇到其他元素都只进行简单的查询操作*/
        for(auto num : s){
            if(num != INT_MIN && s.count(num - 1)){
                continue;
            }

            int cnt = 1;
            while(num != INT_MAX && s.count(num + 1)){
                num++;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};