class Solution {
  public:
    bool solveviaDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, int parent){
        
        visited[u] = true;
        
        for(int v : adj[u]){
            
            if (v == parent) continue;
            if(visited[v]) return true; 
                
            if(solveviaDFS(adj, v, visited, u)){
                return true;
            }
                
            
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        for(auto &x : edges){
            
            int u = x[0];
            int v = x[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>visited(V,false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(solveviaDFS(adj,i,visited,-1)){
                    return true;
                }
            }
        }
        return false;
       
    }
};