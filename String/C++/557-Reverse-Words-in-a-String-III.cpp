class Solution {
public:
    stack<char> st;
    string ans;
    string reverseWords(string s) {
        /*方法一：使用了额外空间
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                st.push(s[i]);
            }
            if(s[i] == ' ' || i == s.size() - 1){
                while(!st.empty()){
                    ans += st.top();
                    st.pop();
                }
                if(i != s.size() - 1) ans += ' '; 
            }
        }
        return ans;*/

        /*方法二：使用迭代器*/
        if(s.size() == 0) return s;

        int front = 0, back = 0;

        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] != ' '){
                back++;
            }
            else{
                reverse(s.begin() + front, s.begin() + back);
                front = back + 1;
                back = front;
            }
        }
        back++;
        reverse(s.begin() + front, s.begin() + back);
        return s;

    }
};