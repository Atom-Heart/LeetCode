/*方法一：hash*/
/*如果一个字符串是回文串的话，肯定有一个对称中心，以这个中心向两边扩散得到的字符串都是回文串*/

class Solution {
public:
    unordered_map<string, int> mp;
    vector<vector<int>> palindromePairs(vector<string>& words) {
        set<pair<int ,int>> ans;
        for(int i = 0; i < words.size(); i++){
            string temp = words[i];
            /*先将每个单词翻转*/
            reverse(temp.begin(), temp.end());
            /*将该单词和其索引建立映射关系*/
            mp[temp] = i; 
        }
        
        for(int i = 0; i < words.size(); i++){
            for(int len = 0; len <= words[i].size(); len++){
                string left_word = words[i].substr(0, len);
                string right_word = words[i].substr(len, words[i].size() - len);
                /*左半边是回文串,而且右边能找到自己的翻转，而且不能是自己本身*/
                if(isPalindrome(left_word) && mp.find(right_word) != mp.end() && mp[right_word] != i){
                    ans.insert(make_pair(mp[right_word], i));
                }
                if(isPalindrome(right_word) && mp.find(left_word) != mp.end() && mp[left_word] != i){
                    ans.insert(make_pair(i, mp[left_word]));
                }
            }
        }
        vector<vector<int>> res;
        for(auto it = ans.begin(); it != ans.end(); it++){
            res.push_back({it->first, it->second});
        }

        for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

        return res;
    }

    bool isPalindrome(string str){
        int left = 0, right = str.size() - 1;
        while(left < right){
            if(str[left++] != str[right--]) return false;
        }
        return true;
    }

};