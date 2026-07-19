class Solution {
  public:
    bool viaDFS(vector<vector<int>> &adj, int u, vector<int> &color){
        
        for(auto &v : adj[u]){
            if(color[v] == -1){
                
                color[v] = 1 - color[u];
                
                if(viaDFS(adj,v,color) == false) return false;
            }
            else if(color[v] == color[u]) return false;
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        for(auto &x : edges){
            int u = x[0];
            int v = x[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(V,-1);
        
        for(int i = 0; i<V; i++){
            
            if(color[i] == -1){
                color[i] = 0;
                
                if(viaDFS(adj,i,color) == false) return false;
            }
        }
        return true;
    }
};