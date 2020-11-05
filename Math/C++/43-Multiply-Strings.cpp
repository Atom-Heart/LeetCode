class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        /*结果最多为m+n个数*/
        vector<int> res(m + n, 0);
        string ans;
        /*从个位开始逐位相乘*/
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                /*乘积mul在res对应的索引位置*/
                int pos_1 = i + j + 1;
                int pos_2 = i + j;
                /*累加到res上*/
                int sum = mul + res[pos_1];
                res[pos_1] = sum % 10;
                res[pos_2] += sum / 10;
            }
        }
        /*前缀可能存的是0（未使用的位）*/
        int i = 0;
        while(i < res.size() && res[i] == 0){
            i++;
        }
        /*将结果转成字符串*/
        for(; i < res.size(); i++){
            ans += (res[i] + '0');
        }  
        return ans.size() == 0 ? "0" : ans;
    }
};