/*暴力法：我的想法是对于每个节点都用DFS进行搜索，得到每个节点的高度并保存，然后遍历结果集得到答案。但是我对无向图的DFS并不熟悉，所以没有尝试*/

/*重点：我一开始没明白这个最小高度树的定义，比方说：[[0,1],[1,2],[2,3],[3,4]]，为什么结果不是3呢？3->4的高度为2啊，应该是最小的。原因在于这是一个无向图，3->4的高度确实是2，但是3->0的高度却是4，所以不对
    一定要明白节点最后只会剩下1个或两个，想象一下某个点可以等分一条直线一样的树，那么这个等分点不是一个就是两个，取决于节点个数是奇数还是偶数    
*/

/*拓扑排序思想优化：观察题目中图的特点，给出的无向图可以理解为一颗多叉树，越是靠里面的节点越可能是最小高度树。于是可以这样去考虑，我们把这个无向图转换成有向图，就是每个相连节点的入度都记为1，先找到所有入度为1的节点，然后把所有节点放入队列，然后不断的bfs，最后找到的就是两边同时向中心靠近的节点，那么这个中间节点相当于把整个距离二分了，那么它当然就是到两边距离最小的节点了*/
class Solution {
public:
    vector<int> ans;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n <= 2){
            for(int i = 0; i < n; i++){
                ans.push_back(i);
            }
            return ans;
        }

        vector<int> indegree(n, 0);
        /*邻接矩阵*/
        vector<vector<int>> adj(n);
        
        /*初始化临界矩阵和入度表*/
        for(auto edge : edges){
            indegree[edge[0]] += 1;
            indegree[edge[1]] += 1;

            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        /*把入度为1的节点加入到队列中*/
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 1) q.push(i);
        }
        /*当队列中只剩下一个或两个节点时，一定就是答案*/
        while(n != 1 && n != 2){
            int size = q.size();
            n -= size;
            /*处理完当前层的所有节点再去处理下一层*/
            for(int i = 0; i < size; i++){
                int node = q.front();
                q.pop();
                for(int j = 0; j < adj[node].size(); j++){
                    indegree[adj[node][j]]--;
                    if(indegree[adj[node][j]] == 1) q.push(adj[node][j]);
                }
            }
        }
        
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};