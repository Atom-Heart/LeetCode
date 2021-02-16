class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char, int> hash;
        for(char ch : s) hash[ch]++;
        vector<pair<char, int>> vec;
        for(auto item : hash) vec.push_back(item);
        sort(vec.begin(), vec.end(), [](const pair<char, int> &a, const pair<char, int> &b){
            return a.second > b.second;
        });
        for(auto item : vec){
            int x = item.second;
            char ch = item.first;
            string str = string(x, ch);
            ans += str;
        }
        return ans;
    }
};