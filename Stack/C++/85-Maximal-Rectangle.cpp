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

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> vec(m, vector<int>(n + 1, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    if(i > 0) vec[i][j] = 1 + vec[i - 1][j];
                    else vec[i][j] = 1;
                }
            }
        }

        int ans = 0;
        /*枚举下边界*/
        for(int i = 0; i < m; i++){
            ans = max(ans, largestRectangleArea(vec[i]));
        }
        return ans;
    }
};