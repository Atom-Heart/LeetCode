class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        /*unordered_map<num1 + num2的值, 出现的次数>*/
        unordered_map<int, int> mp;
        for(int num1 : A){
            for(int num2 : B){
                mp[num1 + num2]++;
            }
        }
        
        int ans = 0;
        for(int num1 : C){
            for(int num2 : D){
                if(mp.find(0 - (num1 + num2)) != mp.end()){
                    ans += mp[0 - (num1 + num2)];
                }
            }
        }
        return ans;
    }
};