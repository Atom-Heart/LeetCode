class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j = 0, i = 0;
        for(; i < g.size() && j < s.size(); i++, j++){
            while(j < s.size() && s[j] < g[i]) j++;
            if(j >= s.size()) break;
        }
        return i;
    }
};