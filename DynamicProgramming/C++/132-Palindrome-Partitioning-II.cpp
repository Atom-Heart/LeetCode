/*方法一：回溯（超时）*/
class Solution {
public:
    int ans = INT_MAX;
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
            if(route.size() < ans){
                ans = route.size();
            }
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
    int minCut(string s) {
        vector<string> route;
        backTracking(s, route, 0);
        return ans - 1;
    }
};
