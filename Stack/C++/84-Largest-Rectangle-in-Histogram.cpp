/*方法一：暴力法，以当前位置所在高度为整个矩形的高度，向两边扩展更新长度*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max = 0;
        int n = heights.size();
        for(int i = 0; i < n; i++){
            int left = i - 1;
            int len = 1;
            while(left >= 0){
                if(heights[left] >= heights[i]){
                    ++len;
                    --left;
                }
                else{
                    break;
                }
            }
            int right = i + 1;
            while(right < n){
                if(heights[right] >= heights[i]){
                    ++len;
                    right++;
                }
                else{
                    break;
                }
            }
            
            int area = heights[i] * len;
            if(area > max){
                max = area;
            }
        }
        return max;
    }
};

/*方法二:单调队列，这个题的核心思想是枚举高度*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> st;
        vector<int> right(n);
        vector<int> left(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            
            if(st.empty()) left[i] = -1;
            else left[i] = st.top();
            st.push(i);  
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()) right[i] = n;
            else right[i] = st.top();
            
            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};