class Solution {
public:
    string compressString(string S) {
        string ans;
        int left = 0, right = 0;
        for(; right <= S.size(); right++){
            if(right == S.size() || S[left] != S[right]){
                ans += S[left];
                ans += to_string(right - left);
                left = right;
            }
        }
        return S.size() > ans.size() ? ans : S;
    }
};