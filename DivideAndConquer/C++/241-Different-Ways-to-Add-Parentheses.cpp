class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        for(int i = 0; i < input.size(); i++){
            char ch = input[i];
            if(ch == '+' || ch == '-' || ch == '*'){
                string str1 = input.substr(0, i);//获取操作符左边的子串
                string str2 = input.substr(i + 1);//获取操作符右边的字串
                /*获取左右子串的运算结果*/
                auto res1 = diffWaysToCompute(str1);
                auto res2 = diffWaysToCompute(str2);
                for(auto num1 : res1){
                    for(auto num2 : res2){
                        if(ch == '+') ans.push_back(num1 + num2);
                        else if(ch == '-') ans.push_back(num1 - num2);
                        else if(ch == '*') ans.push_back(num1 * num2);
                    }
                }
            }
        }
        /*如果是纯数字，ans里面一定是空的，直接返回这个数字*/
        if(ans.size() == 0){
            ans.push_back(stoi(input));
        }
        return ans;
    }
};