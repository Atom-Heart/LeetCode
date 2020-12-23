class Solution {
public:
    string toLowerCase(string str) {
        string ans;
        for(char ch : str){
            if(isupper(ch)){
                ans += tolower(ch);
            }
            else{
                ans += ch;
            }
        }
        return ans;
    }
};