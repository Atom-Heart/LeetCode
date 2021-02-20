class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y){
            string a = to_string(x), b = to_string(y);
            return a + b > b + a;
        });
        string ans;
        for(int num : nums) ans += to_string(num);
        int k = 0;
        while(k + 1 < ans.size() && ans[k] == '0') k++;
        return ans.substr(k);

    }
};