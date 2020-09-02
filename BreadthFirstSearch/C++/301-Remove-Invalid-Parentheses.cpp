/*方法二：暴力BFS*/
class Solution {
public:
    /*最终结果是想得到删除最少括号然后得到的字符串，那么一开始就对原字符出中的每个左右括号都删一遍，看得出的组合有没有目标字串，如果没有，再对字串的每个左右括号再删除一遍，再看有无目标字串*/
    /*以此类推*/
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> remainder;//set去重
        remainder.insert(s);
        bool flag = true;
        while(flag){//这一层遍历完之后再遍历下一层
            for(auto str : remainder){
                if(check(str)){
                    res.push_back(str);
                }
            }
            if(res.size() > 0){
                return res;
            }

            unordered_set<string> next_remainder;//临时set，保存下一层的所有组合
            for(string str : remainder){//遍历这一层的所有组合
                for(int i = 0; i < str.size(); i++){//只要遇到左右括号，就删除
                    if(str[i] == '(' || str[i] == ')'){
                        string temp = str.substr(0, i) + str.substr(i + 1, str.size() - i - 1);
                        next_remainder.insert(temp);
                    }
                }
            }
            remainder = next_remainder;
        }
        return res;
    }
    /*计数器法判断括号是否有效*/
    bool check(string str){
        int count = 0;
        for(char ch : str){
            if(ch == '('){
                count++;
            }
            else if(ch == ')'){
                count--;
            }
            if(count < 0){
                return false;
            }
        }
        return count == 0;
    }
};