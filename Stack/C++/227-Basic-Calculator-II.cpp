class Solution {
public:
    int calculate(string s) {
        stack<char> op;
        stack<int> num;
        unordered_map<char, int> mp;//保存运算符的优先级
        mp['+'] = mp['-'] = 1;
        mp['*'] = mp['/'] = 2;

        for(int i = 0; i < s.size();){
            if(s[i] == ' ') {
                i++;
                continue;
            }
            
            if(s[i] >= '0' && s[i] <= '9'){
                int temp = 0;
                while(s[i] >= '0' && s[i] <= '9'){
                    temp = temp * 10 + (s[i] - '0');
                    i++;
                }
                num.push(temp);
            }
            /*遇到操作符*/
            else{
                /*如果当前运算符的优先级小于等于栈顶运算符的优先级*/
                while(!op.empty() && mp[s[i]] <= mp[op.top()]){
                    int num1 = num.top();
                    num.pop();
                    int num2 = num.top();
                    num.pop();
                    char ch = op.top();
                    op.pop();

                    if(ch == '+'){
                        num.push(num1 + num2);
                    }                    
                    else if(ch == '-'){
                        num.push(num2 - num1);
                    }
                    else if(ch == '*'){
                        num.push(num1 * num2);
                    }
                    else{
                        num.push(num2 / num1);
                    }
                }
                op.push(s[i]);
                i++;
            }
        }
        while(!op.empty()){
            int num1 = num.top();
            num.pop();
            int num2 = num.top();
            num.pop();
            char ch = op.top();
            op.pop();

            if(ch == '+'){
                num.push(num1 + num2);
            }                    
            else if(ch == '-'){
                num.push(num2 - num1);
            }
            else if(ch == '*'){
                num.push(num1 * num2);
            }
            else{
                num.push(num2 / num1);
            }
        }
        return num.top();
    }
};