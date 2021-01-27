class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> stp;
        unordered_map<char, string> pts;
        int i = 0;
        s += ' ';
        for(int k = 0; k < pattern.size(); k++){
            if(i == s.size()) return false;//pattern比s长
            string str;
            while(i < s.size()){
                int j = i + 1;
                while(j < s.size() && s[j] != ' ') j++;
                str = s.substr(i, j - i);
                i = j + 1;
                break;
            }
            if(pts.find(pattern[k]) == pts.end() && stp.find(str) == stp.end()){
                pts[pattern[k]] = str;
                stp[str] = pattern[k];
            }
            /*模式没有出现过，单词出现过*/
            else if(pts.find(pattern[k]) == pts.end() && stp.find(str) != stp.end()){
                return false;
            }
            /*模式出现过，单词不匹配模式*/
            else if(pts.find(pattern[k]) != pts.end() && stp[str] != pattern[k]){
                return false;
            }
        }
        if(i != s.size()) return false;//s比pattren长
        return true;
    }
};