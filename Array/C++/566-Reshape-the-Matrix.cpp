class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if(m * n != r * c) return nums;
        vector<vector<int>> ans(r, vector<int>(c));
        /*二维转一维*/
        vector<int> temp;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                temp.push_back(nums[i][j]);
            }
        }
        /*一维转二维*/
        for(int i = 0; i < temp.size(); i++){
            /*只需要对列数取余或相除就能得到相应的横纵坐标*/
            int x = i / c;
            int y = i % c;
            ans[x][y] = temp[i];
        }
        return ans;
    }
};