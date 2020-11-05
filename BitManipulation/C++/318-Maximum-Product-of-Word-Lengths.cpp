/*位运算+哈希*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks;
        
        /*计算每个单词的掩码*/
        for(auto word : words){
            int bitmask = 0;
            for(int i = 0; i < word.size(); i++){
                char ch = word[i];
                int step = ch - 'a';
                bitmask |= 1 << step;
            }
            masks.push_back(bitmask);
        }

        int ans = INT_MIN;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if((masks[i] & masks[j]) == 0){
                    int temp = words[i].size() * words[j].size();
                    if(temp > ans) ans = temp;
                }
            }
        }
        return ans == INT_MIN ? 0 : ans;

    }
};