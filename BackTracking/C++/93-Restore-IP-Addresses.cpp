class Solution {
public:
    bool isVaild(string s, int begin, int len){
        string str = s.substr(begin, len);
        if(str.size() > 1 && str[0] == '0') return false;//剪枝前导零
        int num = stoi(str);
        if(num >= 0 && num <= 255){
            return true;
        }
        else{
            return false;
        }
    }
    void backTracking(string s, vector<string>& route, int start, int level){
        if(start == s.size()){
            if(level == 4){
                string res = "";
                for(int i = 0; i < 4; i++){
                    res += route[i];
                    if(i != 3){
                        res += '.';
                    }
                }
                ans.push_back(res);
            }
            return;
        }
        
        if(s.size() - start < (4 - level) || s.size() - start > 3 * (4 - level)){
            return;
        }

        for(int i = 1; i <= 4; i++){
            if(start + i > s.size()) return;
            if(isVaild(s, start, i)){
                string temp = s.substr(start, i);
                route.push_back(temp);
                backTracking(s, route, start + i, level + 1);
                route.pop_back();
            }
        }
    }
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        vector<string> route;
        backTracking(s, route, 0, 0);
        return ans;
    }
};