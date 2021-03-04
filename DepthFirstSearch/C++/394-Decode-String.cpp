class Solution {
public:
    string decodeString(string s) {
        string res;
        for(int i = 0; i < s.size(); ){
            /*如果不是数字，那就把s[i]加到最终结果上*/
            if(!isdigit(s[i])) res += s[i++];
            else{
                int j = i;
                /*如果是数字，那么就把这个数字求出来*/
                while(isdigit(s[j])) j++;
                int t = atoi(s.substr(i, j - i).c_str());
                /*k指向[的下一个位置*/
                int k = j + 1, sum = 0;
                /*左括号数量必须大于等于右括号数量*/
                /*就是将嵌套在括号里的内容取出来*/
                /*k最终会指向']'的下一个位置*/
                while(sum >= 0){
                    if(s[k] == '[') sum++;
                    if(s[k] == ']') sum--;
                    k++;
                }
                string str = decodeString(s.substr(j + 1, k - j - 2));
                while(t--) res += str;
                i = k;
            }
        }
        return res;
    }
};