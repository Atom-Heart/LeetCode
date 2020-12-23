/*
*参考https://leetcode-cn.com/problems/count-binary-substrings/solution/ji-shu-er-jin-zhi-zi-chuan-by-leetcode-solution/
*/
class Solution {
public:
    int countBinarySubstrings(string s) {  
        int n = s.size();
        vector<int> vec;
        int i = 0;
        while(i < s.size()){
            char ch = s[i];
            int j = i + 1;
            int cnt = 1;
            while(j < s.size() && s[j] == ch){
                j++;
                cnt++;
            }
            vec.push_back(cnt);
            i = j;
        }
        int ans = 0;
        for(int i = 1; i < vec.size(); i++){
            ans += min(vec[i], vec[i - 1]);
        }
        return ans;
    }
};