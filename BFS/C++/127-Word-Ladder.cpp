class Solution {
public:
	bool helper(string str, unordered_set<string>& front_set, unordered_set<string>& back_set, unordered_set<string>& wordDict, unordered_set<string>& temp) {
		for (int i = 0; i < str.size(); i++) {
			string s = str;
			for (char ch = 'a'; ch <= 'z'; ch++) {
				s[i] = ch;
				if (wordDict.find(s) == wordDict.end()) {
					continue;
				}
				if (back_set.find(s) != back_set.end()) {
					return true;
				}
				temp.insert(s);
			}
		}
		return false;
		
	}
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
		unordered_set<string> front_set{ beginWord };
		unordered_set<string> back_set{ endWord };
		unordered_set<string> wordDict(wordList.begin(), wordList.end());
		int ans = 1;

		while (front_set.size() != 0) {
			unordered_set<string> temp_set;
			ans++;
			for (auto str : front_set) {
				wordDict.erase(str);
			}
			for (auto str : front_set) {
				if (helper(str, front_set, back_set, wordDict, temp_set)) {
					return ans;
				}
			}

			if (temp_set.size() > back_set.size()) {
				front_set = back_set;
				back_set = temp_set;
			}
			else {
				front_set = temp_set;
			}
		}
		return 0;
	}
};