class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        cout<<s.size()<<endl;
        unordered_map<string, int> mp;
        vector<string> ans;
        for(int i = 0; i + 10 <= s.size(); i++){
            string str = s.substr(i, 10);
            mp[str]++;
            if(mp[str] > 1) ans.push_back(str);
        }
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};