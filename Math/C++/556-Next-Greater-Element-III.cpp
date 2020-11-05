/*暴力*/
class Solution {
public:
	int nextGreaterElement(int n) {
		string num = to_string(n);
		for (int i = num.size() - 2; i >= 0; i--) {
            /*找到第一个递增位置*/
			if (num[i] < num[i + 1]) {
				int j = i + 1;
				char tar = num[j];
				int index = j;
                /*找到位置i后面第一个比num[i]大的数*/
				while (j < num.size()) {
					if (num[j] > num[i] && num[j] < tar) {
						tar = num[j];
						index = j;
					}
					j++;
				}
				/*交换*/
				num[index] = num[i];
				num[i] = tar;

                /*对位置i后面的字符串进行排序*/
				string temp = num.substr(i + 1, num.size() - i - 1);
				sort(temp.begin(), temp.end());
                /*得到[0,i]的字符串*/
				string begin = num.substr(0, i + 1);
                /*合并*/
				num = begin + temp;
                break;
			}
		}

        long long val = stol(num);
        /*如果转换结果超出int范围，返回-1*/
        if(val > INT_MAX || val == n) return -1;
        return val;
	}
};

/*单调栈*/
class Solution {
public:
    int nextGreaterElement(int n) {
        stack<char> st;
        string num = to_string(n);
        int idx = -1;
        int i = num.size() - 1;
        for(; i >= 0; i--){
            char ch = num[i];
            while(!st.empty() && ch < num[st.top()]){
                idx = st.top();
                st.pop();
            }

            if(idx != -1){
                char tmp = num[idx];
                num[idx] = num[i];
                num[i] = tmp;
                break;
            }
            st.push(i);
        }
        if(idx == -1) return -1;
        sort(num.begin() + i + 1, num.end());
        long long ans = stol(num);
        return ans > INT_MAX ? -1 : ans;
    }
};