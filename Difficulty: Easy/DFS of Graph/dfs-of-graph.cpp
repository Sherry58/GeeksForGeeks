class Solution {
  public:
    void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int>& result){
        
        if(visited[u] == true) return;
        
        visited[u] = true;
        result.push_back(u);
        
        for(auto &v : adj[u]){
            
            if(!visited[v]){
                
                DFS(adj, v, visited, result);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        
        vector<int> result;
        vector<bool> visited(V, false);
        
        int start = 0;
        DFS(adj, start, visited, result);
        
        return result;
    }
};