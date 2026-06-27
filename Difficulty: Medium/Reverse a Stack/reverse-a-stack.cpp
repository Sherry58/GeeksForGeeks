class Solution {
  public:
    void insertBottom(stack<int> &st, int element){
        if(st.empty()){
            st.push(element);
            return;
        }
        int top = st.top();
        st.pop();
        
        insertBottom(st,element);
        st.push(top);
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        
        int top = st.top();
        st.pop();
        
        reverseStack(st);
        insertBottom(st,top);
    }
};