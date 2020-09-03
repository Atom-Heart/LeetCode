class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0){
            return 0;
        }
        int flag = 1;//用来标记正负数
        int i = 0;
        for(i = 0; i < str.size(); i++){
            if(str[i] == '-'){
                i++;
                flag = -1;
                break;
            }
            else if(str[i] == '+'){
                i++;
                break;
            }
            else if(str[i] == ' '){
                continue;
            }
            else if(str[i] >= '0' && str[i] <= '9'){
                break;
            }
            else{//第一个有效字符不是数字
                return 0;
            }
        }
        if(i == str.size()){//字符串中没有有效字符
            return 0;
        }

        str = str.substr(i, str.size() - i);

        int ans = 0;
        for(i = 0; i < str.size(); i++){
            if(str[i] >= '0' && str[i] <= '9'){
                int temp = (str[i] - '0') * flag;
                if(ans > INT_MAX / 10 || (ans == INT_MAX / 10) && temp > 7){
                    return INT_MAX;
                }
                if(ans < INT_MIN / 10 || (ans == INT_MIN / 10) && temp < -8){
                    return INT_MIN;
                }
                ans = ans * 10 + temp;
            }
            else{
                break;
            }
        }
        return ans;
    }
};