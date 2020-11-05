class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> mp;
        string ans;
        /*key是出现的字母，value是字母出现的次数*/
        for(char ch : s){
            if(mp.find(ch) == mp.end()){
                mp[ch] = 1;
            }
            else{
                mp[ch] += 1;
            }
        }
        /*保存已经在栈中出现过的字母*/
        unordered_set<char> isExist;
        stack<char> st;

        for(int i = 0; i < s.size(); i++){
            /*如果s[i]已经在栈中了*/
            if(isExist.find(s[i]) != isExist.end()){
                mp[s[i]]--;
                continue;
            }
            while(!st.empty() && s[i] < st.top() && mp[st.top()] >= 1){
                isExist.erase(st.top());//标记该字母没有出现在单调栈中
                st.pop();
            }
            st.push(s[i]);
            mp[s[i]]--;//减少s[i]的可用次数
            isExist.insert(s[i]);
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};