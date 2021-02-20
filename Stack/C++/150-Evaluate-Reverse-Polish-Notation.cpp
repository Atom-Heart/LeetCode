class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 0) return 0;
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if((tokens[i][0] >= '0' && tokens[i][0] <= '9') || (tokens[i][0] == '-' && tokens[i].size() > 1)){
                int num = stoi(tokens[i]);
                st.push(num);
            }
            else{
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                if(tokens[i] == "+"){
                    st.push(num1 + num2);
                }
                else if(tokens[i] == "-"){
                    st.push(num1 - num2);
                }
                else if(tokens[i] == "*"){
                    st.push(num1 * num2);
                }
                else if(tokens[i] == "/"){
                    st.push(num1 / num2);
                }
            }
        }
        return st.top();
    }
};