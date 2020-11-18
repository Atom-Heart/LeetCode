class Solution {
public:
    struct cmp{
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            return a.first + a.second < b.first + b.second;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        vector<vector<int>> ans;
        
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(pq.size() < k){
                    pq.push({nums1[i], nums2[j]});
                }
                else{
                    auto temp = pq.top();
                    if(temp.first + temp.second > nums1[i] + nums2[j]){
                        pq.pop();
                        pq.push({nums1[i], nums2[j]});
                    }
                }
            }
        }
        
        while(pq.size() != 0){
            auto item = pq.top();
            pq.pop();
            ans.push_back({item.first, item.second});
        }

        return ans;
    }
};