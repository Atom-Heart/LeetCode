class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ans = 0;
        for(int i = 0, n = apples.size(); i < n || !pq.empty(); i++){
            if(i < n && apples[i] != 0 && days[i] != 0) pq.emplace(i + days[i], apples[i]);
            while(!pq.empty() && pq.top().first <= i) pq.pop();
            if(!pq.empty()){
                ans++;
                auto [x, y] = pq.top();
                pq.pop();
                if(y > 1){
                    pq.emplace(x, y - 1);
                }
            }
        }
        return ans;
    }
};