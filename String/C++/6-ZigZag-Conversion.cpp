/*先从第一行到最后一行，再从最后一行到第一行，把对应行的数据放到临时的string里面，然后想加就是最后的结果*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        vector<string> v(numRows, "");//保存每行的结果，最后相加
        int step = 1;//1代表从上到下，-1代表从下到上
        int row = 0;
        for(int i = 0; i < s.size(); i++){
            v[row].push_back(s[i]);
            /*转向*/
            if(row == 0){
                step = 1;
            }
            else if(row == numRows - 1){
                step = -1;
            }

            row += step;
        }
        string ans = "";
        for(auto str : v){
            ans += str;
        }
        return ans;
    }
};