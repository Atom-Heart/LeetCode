class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        vector<int> temp(nums2.size(), 0);
        /*temp[i]保存着nums2在位置i之后比i大的那个数字*/
        for(int i = nums2.size() - 1; i >= 0; i--){
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }

            if(st.empty()){
                temp[i] = -1;
            }
            else{
                temp[i] = st.top();
            }
            st.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    ans.push_back(temp[j]);
                }
            }
        }
        return ans;
    }
};