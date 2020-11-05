class Solution {
public:
    bool backTracking(string S, vector<int>& route, int begin){
        if(begin >= S.size() && route.size() >= 3){
            return true;
        }
        int len = 1;
        while(len <= S.size() - begin){
            string num1 = S.substr(begin, len);
            /*看当前取的num1是否越界*/
            int top = num1[num1.size() - 1] - '0';
            string pre = num1.substr(0, num1.size() - 1);
            if(pre.size() != 0){//这里经常写错
                int temp = stoi(pre);
                if(INT_MAX / 10 < temp || (INT_MAX / 10 == temp) && top > 7){
                    break;
                }
            }
            
            /*剪枝：去掉有前导0的数*/
            if(num1[0] == '0' && num1.size() > 1){
                len++;
                continue;
            }

            if(route.size() >= 2){
                int num2 = route[route.size() - 1];
                int num3 = route[route.size() - 2];
                if(stoi(num1) - num2 != num3){
                    len++;
                    continue;
                }
            }

            route.push_back(stoi(num1));

            if(backTracking(S, route, begin + len)) return true;
            route.pop_back();
            len++;
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        backTracking(S, ans, 0);
        return ans;
    }
};