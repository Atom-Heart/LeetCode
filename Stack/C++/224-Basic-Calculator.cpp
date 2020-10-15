/*方法一：中缀表达式转后缀表达式，计算后缀表达式得到最终结果*/
class Solution {
public:
    int calculate(string s) {
        vector<string> tokens;
        stack<char> op;
        for(int i = 0; i < s.size();){
            if(s[i] == '+' || s[i] == '-' || s[i] == '('){
                if(s[i] != '('){
                    if(op.empty() || op.top() == '('){
                        op.push(s[i]);
                    }
                    else{
                        while(!op.empty() && op.top() != '('){//这里一定要考虑到运算符的优先级问题，当前运算符的优先级一定要大于栈顶运算符的优先级
                            char ch = op.top();
                            op.pop();
                            string temp(1, ch);
                            tokens.push_back(temp);
                        }
                        op.push(s[i]);
                    }
                }
                else{
                    op.push(s[i]);
                }
                i++;
            }
            else if(s[i] == ')'){
                while(!op.empty() && op.top() != '('){
                    char ch = op.top();
                    op.pop();
                    string temp(1, ch);
                    tokens.push_back(temp);

                }
                op.pop();
                i++;
            }
            else if(s[i] == ' '){
                i++;
                continue;
            }
            else{
                int operand = 0;
                while(s[i] >= '0' && s[i] <= '9'){
                    operand = operand * 10 + (s[i] - '0');
                    i++;
                }
                tokens.push_back(to_string(operand));
            }
        }
        while(!op.empty()){
            char ch = op.top();
            op.pop();
            string temp(1, ch);
            tokens.push_back(temp);
        }
        return evalRPN(tokens);
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        for(auto str : tokens){
            if(str.size() == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')){
                int operand_2 = S.top();
                S.pop();
                int operand_1 = S.top();
                S.pop();
                int result;
                if(str[0] == '+') result = operand_1 + operand_2;
                else if(str[0] == '-') result = operand_1 - operand_2;
                else if(str[0] == '*') result = operand_1 * operand_2;
                else result = operand_1 / operand_2;

                S.push(result);
                continue;
            }
            int sum = 0;
            bool flag = false;
            for(int i = 0; i < str.size(); i++){
                if(str[i] == '-'){
                    flag = true;
                    continue;
                }
                sum = str[i] - '0' + sum * 10;
            }
            if(flag) sum = -sum;
            S.push(sum);
        }
        return S.top();
    }
};

/*双栈法：不需要中缀转后缀计算*/
class Solution {
public:
    int calculate(string s) {
        stack<int> num;//用来保存操作数
        stack<int> op;//用来保存运算符
        int temp = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                continue;
            }
            
            if(s[i] >= '0' && s[i] <= '9'){//如果是一个数字
                if(temp == -1){
                    temp = s[i] - '0';
                }
                else{
                    temp = temp * 10 + (s[i] - '0');
                }
            }
            else{//如果是加减乘除或者左右括号
                if(temp != -1){
                    num.push(temp);
                    temp = -1;
                }
                if(s[i] == '+' || s[i] == '-'){
                    while(!op.empty()){
                        if(op.top() == '(') break;
                        
                        int num1 = num.top();
                        num.pop();
                        int num2 = num.top();
                        num.pop();
                        if(op.top() == '+'){
                            num.push(num1 + num2);
                        }
                        else{
                            num.push(num2 - num1);
                        }
                        op.pop();
                    }
                    op.push(s[i]);
                }
                else{
                    /*遇到左括号*/
                    if(s[i] == '('){
                        op.push(s[i]);
                    }
                    /*遇到右括号*/
                    if(s[i] == ')'){
                        while(op.top() != '('){
                            int num1 = num.top();
                            num.pop();
                            int num2 = num.top();
                            num.pop();
                            if(op.top() == '+'){
                                num.push(num1 + num2);
                            }
                            else{
                                num.push(num2 - num1);
                            }
                            op.pop();
                        }
                        op.pop();
                    }
                }

            }
        }
        if(temp != -1){
            num.push(temp);
        }
        while(!op.empty()){
            int num1 = num.top();
            num.pop();
            int num2 = num.top();
            num.pop();
            if(op.top() == '+'){
                num.push(num1 + num2);
            }
            else{
                num.push(num2 - num1);
            }
            op.pop();
        }
        return num.top();
    }
};