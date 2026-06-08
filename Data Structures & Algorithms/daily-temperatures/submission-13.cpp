class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        st.push(0);
        int n=temperatures.size();
        vector<int>ans(n);
        
        for(int i=1;i<n;i++){
            if(temperatures[i-1]<temperatures[i]){
                
                while(!st.empty() &&temperatures[st.top()]<temperatures[i]){
                    ans[st.top()]=i-st.top();
                    st.pop();
                }
            }
            st.push(i);
            
        }
        return ans;
    }
};
