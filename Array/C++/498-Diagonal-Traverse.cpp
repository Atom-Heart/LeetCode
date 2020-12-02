class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& w) {
        vector<int> res;
        if(w.empty() || w[0].empty()) return res;
        int n = w.size();
        int m = w[0].size();
        for(int i = 0; i < n + m - 1; i++){
            if(i % 2 == 0){
                /*枚举行的取值*/
                /*行的最大取值是n-1*/
                /*如果i = n + m - 2时，应该在处理最后一条对角线，行号是n-1，每往前数一条对角线，行号就会减1，
                所以能往前数n - 1 - (n + m - 2 - i)，因为当i = n + m - 2时，就不能往前数了，而且最多减到0，不会减到负数.
                又因为是从下往上数的，所j--，表示向上移动
                */
                for(int j = min(i, n - 1); j >= max(0, i + 1 - m); j--){
                    /*每条正对角线上的横纵坐标值之和相等*/
                    int num = w[j][i - j];
                    res.push_back(num);
                }
            }
            else{
                for(int j = max(0, i + 1 - m); j <= min(i, n - 1); j++){
                    int num = w[j][i - j];
                    res.push_back(num);
                }
            }
        }
        return res;
    }
};