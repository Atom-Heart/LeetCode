class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);//保存每个节点的后继节点
        vector<int> indegree(numCourses, 0);//保存每个节点的入度
        /*初始化*/
        for(int i = 0; i < prerequisites.size(); i++){
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        /*把所有入度为0的节点入队*/
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0) q.push(i);
        }
        int cnt = 0;//用来记录出队了多少个元素
        while(!q.empty()){
            ++cnt;
            int course = q.front();
            q.pop();
            /*把该节点对应的所有后继节点的入度都减1*/
            for(int i = 0; i < adj[course].size(); i++){
                indegree[adj[course][i]]--;
                /*如果某个后继节点的入度为0，那就把这个节点加入到队列中*/
                if(indegree[adj[course][i]] == 0){
                    q.push(adj[course][i]);
                }
            }
        }
        return cnt == numCourses ? true : false;
        
    }
};