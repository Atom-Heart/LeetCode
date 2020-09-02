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

/*方法二:单调队列，这个题的核心思想就是在当前位置，在左右两个方向去寻找第一个小于当前高度的位置*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        /*这是为了方便处理边界条件*/
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        
        int n = heights.size();

        for(int i = 0; i < n; i++){
            /*出现了第一个小于栈尾元素的数，这就是右边第一个小于当前位置高度的下标*/
            while(!st.empty() && heights[st.top()] > heights[i]){
                int cur = st.top();//以当前位置元素为高度
                st.pop();
                int left = st.top();//这里如果不做上面的加0处理就会出现越界情况
                int right = i - 1;
                ans = max(ans, (right - left) * heights[cur]);
            }
            /*如果高度是递增的，那么直接入栈*/
            st.push(i);
        }
        return ans;
    }
};