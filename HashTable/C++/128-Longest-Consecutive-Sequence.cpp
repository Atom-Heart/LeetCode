class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int num : nums) s.insert(num);
        
        int ans = 0;
        for(int num : s){
            if(s.count(num - 1)) continue;

            int cnt = 1;
            while(s.count(num + 1)){
                num++;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};