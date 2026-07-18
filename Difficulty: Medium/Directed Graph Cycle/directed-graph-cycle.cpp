class Solution {
	public:
	bool isCyclicDFS(vector<vector<int>> & adj, int u, int parent, vector<bool>& visited, vector<bool>& inRecursion) {
		
		visited[u] = true;
		inRecursion[u] = true;
		
		for (auto &v : adj[u]) {
			
			if (visited[v] == false) {
				if (isCyclicDFS(adj, v, u, visited, inRecursion) == true)
					return true;
			}
			else if (inRecursion[v] == true)
				return true;
		}
		
		inRecursion[u] = false;
		
		return false;
		
	}
	bool isCyclic(int V, vector<vector<int>> &edges) {
		// code here
		vector<bool> visited(V, false);
		vector<bool> inRecursion(V, false);
		
		vector<vector<int>> adj(V);
		
		for (auto &x : edges) {
			
			int u = x[0];
			int v = x[1];
			
			adj[u].push_back(v);
			
		}
		
		for (int i = 0; i < V; i++) { /* i is for the start node */
			if (visited[i] == false) {
				
				if (isCyclicDFS(adj, i, -1, visited, inRecursion) == true) {
					return true;
				}
			}
		}
		return false;
	}
};
