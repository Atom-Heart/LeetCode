class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string s){
        if(s.size() == 1) return true;
        int begin = 0;
        int end = s.size() - 1;

        while(begin <= end){
            if(s[begin] != s[end]) return false;
            begin++;
            end--;
        }
        return true;
    }
    
    void backTracking(string s, vector<string>& route, int begin){
        if(begin == s.size()){
            ans.push_back(route);
            return;
        }

        for(int i = 1; i <= s.size(); i++){
            if(begin + i > s.size()){
                break;
            }
            string temp = s.substr(begin, i);
            if(isPalindrome(temp)){
                route.push_back(temp);
                backTracking(s, route, begin + i);
                route.pop_back();
            }
            else{
                continue;
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<string> route;
        backTracking(s, route, 0);
        return ans;
    }
};