class Solution {
public:

    vector<int> topologicalSort(vector<vector<int>> &adj, int u, vector <int> indegree){
        int V= adj.size();
        int cnt=0;
        vector <int> result;
        queue<int> q;
        for (int i=0;i<V;i++){
            if (indegree[i]==0){
                cnt++;
                result.push_back(i);
                q.push(i);
            }
        }

        while (!q.empty()){
            int node = q.front();
            q.pop();
            for (auto &v: adj[node]){
                indegree[v]--;
                if (indegree[v]==0){
                    cnt++;
                    result.push_back(v);
                    q.push(v);
                }
            }
        }
        if (cnt ==V){
            return result; 
        }

        return {};




    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        //Using Kahn's algorithm

        vector <int> indegree(V,0);
        vector<vector<int>> adj(V);


        for (auto &p: prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        return topologicalSort(adj,0,indegree);


        
    }
};