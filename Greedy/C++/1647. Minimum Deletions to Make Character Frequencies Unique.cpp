/*贪心:统计每个字母出现的词频，然后从大到小排序。如果当前位置出现的频率大于等于上一个位置出现的频率，那么就删除当前出现的频率直到小于上一个位置出现的频率。这样当前位置之前的一定是降序的，删除当期位置的出现频率只会影响当前位置之后的位置，而不会影响之前的*/

/*
  0 1 2       
1.2 2 1
2.2 1 1
3.2 1 0

*/
class Solution {
public:
    int minDeletions(string s) {
        vector<int> words(26, 0);
        for(char ch : s) words[ch - 'a']++;
        int ans = 0;
        sort(words.rbegin(), words.rend());
        for(int i = 1; i < 26; i++){
            if(words[i] == 0) break;
            while(words[i] >= words[i - 1] && words[i] > 0){
                ans++;
                words[i]--;
            }
        }
        return ans;
    }
};