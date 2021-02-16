class Solution {
public:
    vector<string> ans;
    vector<string> hash = {
        "", "", "abc",
        "def", "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        dfs(digits, 0, "");
        return ans;
    }

    void dfs(string digits, int level, string route){
        if(level == digits.size()){
            ans.push_back(route);
            return;
        }

        string str = hash[digits[level] - '0'];
        for(int i = 0; i < str.size(); i++){
            dfs(digits, level + 1, route + str[i]);
        }
    }
};