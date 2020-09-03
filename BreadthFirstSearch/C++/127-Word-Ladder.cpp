/*方法一：单向搜索，从上至下*/
class Solution {
public:
    bool check(string s1, string s2){
        int len = s1.size();
        int count = 0;
        for(int i = 0; i < len; i++){
            if(s1[i] != s2[i]){
                count++;
                if(count >= 2){
                    return false;
                }
            }
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 0;
        unordered_map<string, bool> mp;

        /*标记字典中的单词都没有被访问过*/
        for(auto str : wordList){
            mp[str] = false;
        }

        unordered_set<string> set;//存放每层的数据
        set.insert(beginWord);

        while(set.size() != 0){
            unordered_set<string> next_set;//保存下一层的数据
            for(auto str_1 : set){
                for(auto str_2 : wordList){
                    if(str_1 == endWord) return ans + 1;
                    if(check(str_1, str_2) && mp[str_2] == false){
                        next_set.insert(str_2);
                        mp[str_2] = true;
                    }
                }
            }
            set = next_set;
            ++ans;//进入下一层
        }
        return 0;
    }
};

/*方法二：双向BFS*/
