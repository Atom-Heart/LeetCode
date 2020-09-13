class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string ans = "";
        int min_len = INT_MAX;
        /*找出所有字符串中的最小长度*/
        for(auto str : strs){
            if(str.size() < min_len){
                min_len = str.size();
            }
        }
        /*依次遍历每个string，看他们相同位置的字符是否相同*/
        for(int i = 0; i < min_len; i++){
            for(int j = 0; j < strs.size() - 1; j++){
                if(strs[j][i] != strs[j + 1][i]){
                    return ans;
                }
            }
            ans += strs[0][i];
        }
        return ans;
        
        
    }
};