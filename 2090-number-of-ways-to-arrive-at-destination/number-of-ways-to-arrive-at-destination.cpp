class Solution {
public:
    typedef pair<int, long long> p;
    const int MOD = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<p>>adj(n); // intialise n adj list


        for (auto u: roads){ // undirected graph
            adj[u[0]].push_back({u[1],u[2]});
            adj[u[1]].push_back({u[0],u[2]});
        }
        
       


        // distance , node -> min heap
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector <long long>time(n,LONG_LONG_MAX);
        vector<int> ways(n,0); // to cnt no. of shortest way
        pq.push({0,0}); //node, wt
        time[0]=0;
        ways[0]=1;


        while(!pq.empty()){
            auto [t, node]= pq.top();
           

            pq.pop();
            if (t> time[node]) continue; // if t is greater 

            for (auto &[v, wt]: adj[node]){
                if (time[node]+wt<time[v]){
                    time[v]= time[node]+wt;
                    ways[v]=ways[node];
                    pq.push({time[v],v});
                }
                else if (time[node]+wt== time[v]){
                    ways[v]= (ways[v]+ways[node])%MOD;
                }
            }


            
        }

        return ways[n-1]%MOD;

        

    }
};