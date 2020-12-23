/*方法一：堆*/
class Solution {
public:

    struct cmp
    {
        /*第一个参数如果满足条件则优先级大，否则第二个参数优先级大*/
        /*在优先队列中，优先级大的会被放到堆底，优先级小的会被放在堆顶*/
        bool operator()(const pair<string, int>& a,const pair<string, int>& b)const
        {//a,b频数大的，优先级大，频数相等，字典序小的优先级大.
            if(a.second != b.second) return a.second > b.second;
            else return a.first < b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        unordered_map<string, int> mp;
        for(auto word : words){
            mp[word]++;
        }
        cmp order;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(pq.size() < k){
                pq.push(*it);
            }
            else if(order(*it, pq.top())){//这里是精髓，帮助理解排序函数的本质
                pq.pop();
                pq.push(*it);
            }
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};