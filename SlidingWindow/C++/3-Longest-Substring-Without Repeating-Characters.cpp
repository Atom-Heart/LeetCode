class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, len = 0;
        unordered_map<char, int> windows;
        while(right < s.size()){
            char ch = s[right];
            right++;
            windows[ch]++;
            while(windows[ch] > 1){
                char d = s[left];
                left++;
                windows[d]--;
            }

            len = max(len, right - left);
            cout<<len<<endl;
        }
         return len;
    }
   
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_map<char, int> mp;
        int len = 0;
        for(int right = 0; right < s.size(); right++){
            mp[s[right]]++;
            while(mp[s[right]] > 1){
                mp[s[left]]--;
                left++;
            }
            len = max(len, right - left + 1);
        }
        return len;

    }
};