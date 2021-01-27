class Solution {
public:
    /*不太会的点在于如何表示窗口合法*/
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for(char ch : t) need[ch]++;
        int left = 0, right = 0, len = INT_MAX;
        int begin = -1;
        int vaild = 0;
        for(; right < s.size(); right++){            
            if(need.count(s[right])){
                window[s[right]]++;
                if(window[s[right]] == need[s[right]])
                    vaild++;
            }

            while(vaild == need.size()){
                if(right - left + 1 < len){
                    len = right - left + 1;
                    begin = left;
                }

                if(need.count(s[left])){
                    if(window[s[left]] == need[s[left]]){
                        vaild--;
                    }
                    window[s[left]]--;
                }
                left++;
            }
        }
        return len == INT_MAX ? "" : s.substr(begin, len);
    }
};