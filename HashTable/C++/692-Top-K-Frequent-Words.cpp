class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash;
        for(auto word : words) hash[word]++;
        vector<pair<string, int>> vec;
        for(auto item : hash) vec.push_back(item);
        sort(vec.begin(), vec.end(), [](const pair<string, int> &a, const pair<string, int> &b){
            if(a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });
        


        vector<string> ans;
        for(int i = 0; i < vec.size() && k; i++, k--){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};