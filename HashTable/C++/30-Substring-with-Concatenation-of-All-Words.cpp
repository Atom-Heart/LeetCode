/*方法一：哈希表*/
/*这个题的难点主要在于字符串的匹配，比方说words中有单词A,B.那么可以组成AB和BA，如果有A,B,C,那么就会有ABC, ACB, BAC, BCA,CAB,CBA，这些情况的匹配就太复杂了
这个时候就可以取考虑不去管它们的顺序，而是专注于它们出现的个数，如果匹配可以成功，那么说明words中单词出现的次数和s中字串中出现的次数是一样的*/

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		unordered_map<string, int> allWord;
		vector<int> ans;
		/*把words中所有单词做映射*/
		for (auto str : words) {
			if (allWord.find(str) == allWord.end()) {
				allWord.insert(make_pair(str, 1));
			}
			else {
				int val = allWord[str];
				allWord[str] = val + 1;
			}
		}

		int wordLen = words[0].size();//单词的长度
		int wordNum = words.size();//单词的个数
        
        int temp = s.size() - wordLen * wordNum;//匪夷所思，s.size() - wordLen * wordNum竟然写在for循环里会出错，结果是一个非常大的数
		for (int i = 0; i <= temp; i++) {
			int num = 0;//已经匹配的单词个数
			unordered_map<string, int> curWord;
			while (num < wordNum) {
				string word = s.substr(i + num * wordLen, wordLen);
				if (allWord.find(word) != allWord.end()) {//该字串单词存在于words中
					if (curWord.find(word) == curWord.end()) {//该单词还没有被映射到curword中
						curWord.insert(make_pair(word, 1));
					}
					else {
						curWord[word] += 1;
					}
					/*判断字串单词的个数是不是超过allWord中的个数,如果是，直接退出*/
					if (curWord[word] > allWord[word]) {
						break;
					}
					num++;//匹配到的单词数加1
				}
				else {
					break;
				}
			}
			if (num == wordNum) {//匹配成功
				ans.push_back(i);
			}
		}
		return ans;
	}
};