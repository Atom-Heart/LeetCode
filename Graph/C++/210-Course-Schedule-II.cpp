class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int course = q.front();
            q.pop();
            for(int i = 0; i < adj[course].size(); i++){
                indegree[adj[course][i]]--;
                if(indegree[adj[course][i]] == 0){
                    q.push(adj[course][i]);
                    ans.push_back(adj[course][i]);
                } 
            }
        }
        if(ans.size() == numCourses){
            return ans;
        }
        else{
            return {};
        }
    }
};