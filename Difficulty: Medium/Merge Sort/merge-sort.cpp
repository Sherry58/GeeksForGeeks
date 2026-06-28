class Solution {
  public:
    void merge(vector<int>& arr, int l, int m, int r){
        vector<int> temp;
        
        int i = l;
        int j = m+1;
        
        while(i <= m and j <= r){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i <= m){
            temp.push_back(arr[i]);
            i++;
        }
        while(j <= r){
            temp.push_back(arr[j]);
            j++;
        }
        for(int i = l; i <= r; i++){
            arr[i] = temp[i-l];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l >= r) return;
        
        int m = (l+r)/2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        
        merge(arr, l, m, r);
    }
};