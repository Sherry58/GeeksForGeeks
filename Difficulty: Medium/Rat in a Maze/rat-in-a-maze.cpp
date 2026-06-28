class Solution {
  public:
    vector<string> result;
    int n;
    
    void solve(int i, int j, vector<vector<int>>& maze, string& temp){
        if(i<0 or i>=n or j<0 or j>=n or maze[i][j]==0) return;
        if(i==n-1 and j==n-1){
            result.push_back(temp);
            return;
        }
        maze[i][j]=0;
        
        temp.push_back('D');
        solve(i+1,j,maze,temp);
        temp.pop_back();
        
        temp.push_back('L');
        solve(i,j-1,maze,temp);
        temp.pop_back();
        
        temp.push_back('R');
        solve(i,j+1,maze,temp);
        temp.pop_back();
        
        temp.push_back('U');
        solve(i-1,j,maze,temp);
        temp.pop_back();
        
        maze[i][j] = 1;
    }
      
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        n = maze[0].size();
        
        if (maze[0][0] == 0 || maze[n-1][n-1] == 0)
            return {};
            
        string path = "";
        solve(0,0,maze,path);
        
        return result;
        
    }
};