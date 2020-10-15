/*解法一：暴力法(超时)，既然是在字符串前面添加字符使其转化为字符串，那么就去掉字符串结尾的1~n - 1个字符，看剩下的字串是不是回文串，如果是，就将去掉的字符串逆序后加到剩下的字符串前*/
class Solution {
public:
    bool isPalindrome(string s){
        int left = 0, right = s.size() - 1;
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    string shortestPalindrome(string s) {
        if(s.size() == 0 || isPalindrome(s)) return s;
        int len = s.size();
        int size = 1;
        for(int i = len - 1; i > 0; i--){
            string str1 = s.substr(i, size);
            string str2 = s.substr(0, len - size);
            cout<<str1<<endl;
            cout<<str2<<endl;
            if(isPalindrome(str2)){//如果前面是回文串了
                reverse(str1.begin(), str1.end());//逆置后面的字串
                s.insert(0, str1);
                cout<<s<<endl;
                break;
            }
            size++;
        }
        return s;
    }
};

/*解法二（超时）：先将原字符串逆序，一个缩短尾巴，一个缩短头，如果两个字符串相等，那么这个字符串就是从头开始的最长回文子串*/
/*这道题要考虑两个基本点，一：字符是添加到原字符串前面的。二：所以我只要找到原字符串从头开始的最长回文子串*/
class Solution {
public:

    string shortestPalindrome(string s) {
        string str = s;
        reverse(str.begin(), str.end());
        int len = s.size();
        for(int i = 0; i < s.size(); i++){
            string temp1 = s.substr(0, len - i);
            string temp2 = str.substr(i, len - i);
            if(temp1 == temp2){
                string temp3 = str.substr(0, i);
                s.insert(0, temp3);
                break;
            }
        }
        return s;
    }
};
