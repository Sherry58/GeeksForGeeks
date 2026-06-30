class Solution {
  public:
    vector<string> result;
    
    void solve(string &s, string curr, int idx){
        if(idx>=s.size()){
            result.push_back(curr);
            return;
        }
        
        curr.push_back(s[idx]);
        solve(s, curr, idx+1);
        
        curr.pop_back();
        solve(s, curr, idx+1);
        
    }
    vector<string> powerSet(string &s) {
        // Code here
        string curr = "";
        solve(s,curr,0);
        
        sort(result.begin(), result.end());
        
        return result;
    }
};