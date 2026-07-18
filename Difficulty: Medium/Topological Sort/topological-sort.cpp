class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> indegree(V,0);
        vector<vector<int>> adj(V);
        
        for(auto &p : edges){ // populate kar diya indegree ko
            
            indegree[p[1]]++;
        }
        
        for(auto &x : edges){ // creating the adjacency list
            
            int u = x[0];
            int v = x[1];
            
            adj[u].push_back(v);
        }
        
        queue<int> que;
        
        for(int i = 0; i<V ; i++){ // pushing those nodes whose indegree are 0 initially into the queue
            
            if(indegree[i] == 0) que.push(i);
        }
        
        vector<int> res;
        
        while(!que.empty()){
            
            int u = que.front();
            que.pop();
            
            res.push_back(u);
            
            for(auto &v : adj[u]){
                indegree[v]--;
                
                if(indegree[v] == 0) que.push(v);
                
            }
        }
        
        return res;
    }
};