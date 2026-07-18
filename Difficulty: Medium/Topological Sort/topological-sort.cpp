class Solution {
  public:
    vector<int> res;
    stack<int> st;
    
    void viaDFS(vector<vector<int>>& adj, int u, vector<bool>& visited){
        
        visited[u] = true;
        
        for(auto &v : adj[u]){
            
            if(visited[v] == false){
                
                viaDFS(adj, v, visited);
            }
        }
        st.push(u);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<bool> visited(V,false);
        
        for(auto& x : edges){
            
            int u = x[0];
            int v = x[1];
            
            adj[u].push_back(v);
        }
        
        
        for(int i = 0; i < V; i++){
            
            if(visited[i] == false){
                
                viaDFS(adj, i, visited);
            }
            
        }
        
        while(!st.empty()){
            
            res.push_back(st.top());
            
            st.pop();
            
        }
        
        return res;
        
    }
};