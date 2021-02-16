class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> window, need;
        vector<int> ans;
        for(char ch : p){
            need[ch]++;
        }

        int left = 0, right = 0, vaild = 0;
        for(; right < s.size(); right++){
            if(need.count(s[right])){
                window[s[right]]++;
                if(window[s[right]] == need[s[right]]){
                    vaild++;
                }
                if(vaild == need.size()){
                    ans.push_back(left);
                }
            }

            if(right - left + 1 == p.size()){
                if(need.count(s[left])){
                    if(window[s[left]] == need[s[left]]){
                        vaild--;
                    }
                    window[s[left]]--;
                }
                left++;
            }
        }
        return ans;
    }
};