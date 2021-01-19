/*
*利用了并查集，允许交换的二维数组可以理解成连通块之间的边，问题就可以转化成：如果任意两个结点在并查集内是联通的，说明这两个结点可以相互交换位置。
*如果target[i]不存在于source内，那么怎么换都不会匹配的，一定会产生汉明距离；
*如果存在，且两个是联通的，那就把target[i]从hash里移除，避免重复使用
*/

class Solution {
public:
    vector<int> p;

    int find(int x){
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        for(int i = 0; i < n; i++) p.push_back(i);
        for(auto &item : allowedSwaps) p[find(item[0])] = find(item[1]);

        /*每个祖宗结点存储了整个联通集合的元素值*/
        vector<unordered_multiset<int>> hash(n);
        for(int i = 0; i < n; i++){
            hash[find(i)].insert(source[i]);
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            auto &h = hash[find(i)];
            if(h.count(target[i])) h.erase(h.find(target[i]));//移除，防止重复利用
            else res++;
        }
        return res;

        
    }
};