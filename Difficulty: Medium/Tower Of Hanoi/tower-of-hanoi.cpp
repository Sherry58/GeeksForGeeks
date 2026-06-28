class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        if(n <= 1) return n;
        
        
        int x = towerOfHanoi(n-1, from, aux, to);
        int y = towerOfHanoi(n-1, aux, to, from);
        
        return x+1+y;
    }
};