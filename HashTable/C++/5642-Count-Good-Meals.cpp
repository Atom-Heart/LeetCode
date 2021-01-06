class Solution {
public:
    const int N = 1e9 + 7;
    int countPairs(vector<int>& deliciousness) {
        /*数字 -> 出现次数*/
        unordered_map<int, int> mp;
        using LL = long long;
        
        LL ans = 0;
        for(int i = 0; i < deliciousness.size(); i++){
            for(int j = 0; j < 22; j++){
                int target = pow(2, j);
                if(target - deliciousness[i] < 0) continue;
                if(mp.count(target - deliciousness[i])){
                    ans += mp[target - deliciousness[i]];
                }
            }
            ++mp[deliciousness[i]];
        }
        return ans % N;

    }
};