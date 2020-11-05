/*方法一：利用istringstream处理表示大数的字符串，将字符串转成long long类型进行运算*/
class Solution {
public:
    vector<long long> route;
    bool backTracking(string num, vector<long long>& route, int begin){
        if(begin >= num.size() && route.size() >= 3){
            for(int n : route){
                cout<<n<<" ";
            }
            return true;
        }
        int len = 1;//数字起码有一个长度
        while(len <= num.size() - begin){//数字最大长度为[1, num.size() - begin]
            string temp = num.substr(begin, len);
            /*剪枝：有前导零直接跳过*/
            if(temp[0] == '0' && temp.size() > 1){
                len++;
                continue;
            }


            long long num1;
        
            istringstream is1(temp);
                
            is1 >> num1;


            /*剪枝：如果当前要加入的数字不等于前两个数之和，不用继续回溯*/
            if(route.size() >= 2){
                long long num2 = route[route.size() - 1];
                long long num3 = route[route.size() - 2];
                if(num1 != num2 + num3){
                    len++;
                    continue;
                }
            }

            route.push_back(num1);
            if(backTracking(num, route, begin + len)) return true;
            route.pop_back();
            len++;
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        return backTracking(num, route, 0);
    }
};

/*方法二：利用大数加法去处理数字溢出*/
class Solution {
public:
    vector<string> route;
    bool backTracking(string num, vector<string>& route, int begin){
        if(begin >= num.size() && route.size() >= 3){
            return true;
        }
        int len = 1;//数字起码有一个长度
        while(len <= num.size() - begin){//数字最大长度为[1, num.size() - begin]
            string num1 = num.substr(begin, len);
            /*剪枝：有前导零直接跳过*/
            if(num1[0] == '0' && num1.size() > 1){
                len++;
                continue;
            }

            /*剪枝：如果当前要加入的数字不等于前两个数之和，不用继续回溯*/
            if(route.size() >= 2){
                string num2 = route[route.size() - 1];
                string num3 = route[route.size() - 2];
                if(num1 != addTwoNumbers(num2, num3)){
                    len++;
                    continue;
                }
            }

            route.push_back(num1);
            if(backTracking(num, route, begin + len)) return true;
            route.pop_back();
            len++;
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        return backTracking(num, route, 0);
    }
    string addTwoNumbers(string num1, string num2) {
	    int x = 0, y = 0, sum = 0, carry = 0;
	    string ans;

	    int i = num1.size() - 1, j = num2.size() - 1;
	    while (i >= 0 && j >= 0) {
		    x = num1[i] - '0';
		    y = num2[j] - '0';

		    sum = x + y + carry;
		    carry = sum / 10;
		    ans += (sum % 10 + '0');

		    i--;
		    j--;
	    }
        /*处理两个操作数不对其的情况*/
	    while (i >= 0) {
		    sum = (num1[i] - '0') + carry;
		    carry = sum / 10;
		    ans += (sum % 10 + '0');
		    i--;
	    }
	    while (j >= 0) {
		    sum = (num2[j] - '0') + carry;
		    carry = sum / 10;
		    ans += (sum % 10 + '0');
		    j--;
	    }

        /*如果最高位有进位的话，如 99 + 1*/
        if(carry == 1){
            ans += (carry + '0');
        }
	    reverse(ans.begin(), ans.end());
	    return ans;
    }
};

