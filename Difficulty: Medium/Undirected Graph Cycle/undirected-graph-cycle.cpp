class Solution {
  public:
    bool isCycleBFS(vector<vector<int>>& adj, int u, vector<bool>& visited){
        
        visited[u] = true;
        
        queue<pair<int,int>> que;
        que.push({u, -1});
        
        while(!que.empty()){
            
            pair<int, int> pr = que.front();
            que.pop();
            
            int curr = pr.first;
            int parent = pr.second;
            
            for(int &v : adj[curr]){
                
                if(visited[v] == false){
                    visited[v] = true;
                    
                    que.push({v, curr}); 
                }
                else if(v != parent) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<bool> visited(V, false);
        vector<vector<int>> adj(V);
        
        for(auto &x : edges){
            
            int u = x[0];
            int v = x[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 0; i < V; i++){
            
            if(visited[i] == false){
                
                if(isCycleBFS(adj, i, visited) == true) return true;
            }
        }
        return false;
        
    }
};