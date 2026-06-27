class Node{
public:
    int value,row,col;
    
    Node(int value, int row, int col){
        this->value = value;
        this->row = row;
        this->col = col;
    }
};

class cmp{
public:
    bool operator()(const Node& a, const Node& b) const{
        return a.value > b.value;
    }
};
class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        
        priority_queue<Node, vector<Node>, cmp> pq;
        for(int i = 0; i < n; i++){ // initial insertion only
            pq.push({mat[i][0], i, 0});
        }
        vector<int> res;
        while(!pq.empty()){
            Node p = pq.top();
            int value = p.value;
            int row = p.row;
            int col = p.col;
            
            res.push_back(value);
            pq.pop();
            
            if(col+1 < m){
                pq.push({mat[row][col+1], row, col+1});
            }
        }
        return res;
    }
};
