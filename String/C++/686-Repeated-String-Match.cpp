class Solution {
public:
	int repeatedStringMatch(string a, string b) {
		int ans = 0;
		/*在a中寻找b的第一个起点*/
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[0]) {
				ans++;
				int j = i;
				int k = 0;
				while (a[j] == b[k]) {
					j++; k++;
					if (k >= b.size()) {
						return ans;
					}
					if (j >= a.size()) {
						j = 0;
						ans++;
					} 
				}
			}
			ans = 0;
		}
		return -1;
	}
};