class Solution {
  public:
    void BFS(vector<vector<int>> &adj, int u, vector<bool>& visited, vector<int>& result){
        
        if(visited[u] == true) return;
        
        visited[u] = true;
        queue<int> q;
        q.push(u);
        
        
        while(!q.empty()){
            
            int u = q.front();
            q.pop();
            
            result.push_back(u);
            
            for(int &v : adj[u]){
                if(!visited[v]){
                    
                    q.push(v);
                    visited[v] = true;
                    
                }
            }
        }
        
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        vector<int> result;
        vector<bool> visited(V, false);
        
        int start = 0;
        BFS(adj, start, visited, result);
        
        return result;
    }
};  