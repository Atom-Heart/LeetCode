class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        for(int i = 0; i < nums.size(); i++){
            if(i < k - 1){
                while(!q.empty() && nums[i] > q.back()){
                    q.pop_back();
                }
                q.push_back(nums[i]);
            }
            else{
                while(!q.empty() && nums[i] > q.back()){
                    q.pop_back();
                }
                q.push_back(nums[i]);
                
                ans.push_back(q.front());
                
                if(!q.empty() && nums[i - k + 1] == q.front()){
                    q.pop_front();  
                }
            }
        }
        return ans;
    }
};