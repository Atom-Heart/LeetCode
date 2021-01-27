class Solution {
public:
    int minCharacters(string a, string b) {
        int m = a.size(), n = b.size();
        vector<int> s1(26);
        vector<int> s2(26);

        for(char ch : a) s1[ch - 'a']++;
        for(char ch : b) s2[ch - 'a']++;

        int cnt_3 = INT_MAX;
        
        /*相当于遍历26个字母，看换成每个字母需要多少操作次数*/
        for(int i = 0; i < 26; i++){
            cnt_3 = min(cnt_3, m + n - (s1[i] + s2[i]));
        }

        return min(cnt_3, min(helper(s1, s2), helper(s2, s1)));
    }

    /*在b~z里面选一个字母作为边界，如果想让a中每一个字母都小于b中每一个字母，那么就统计一下a中大于边界的字母个数，统计一下b中小于边界字母的个数*/
	/*枚举b的下界*/
	/*使a严格小于b*/
    int helper(vector<int> a, vector<int> b){
        int ans = INT_MAX;
        for(int i = 1; i < 26; i++){
            int cnt = 0;
            for(int j = i; j < 26; j++){
                cnt += a[j];
            }
            for(int j = 0; j < i; j++){
                cnt += b[j];
            }
            ans = min(ans, cnt);
        }
        return ans;
    }

};