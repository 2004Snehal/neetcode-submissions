class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>>times(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            times[i].first=position[i];
            times[i].second=double(target-position[i])/double(speed[i]);
        }
        sort(times.begin(),times.end());
        st.push(0);

        // 1.33 1
        // 0 1 2 3 4
        cout<<times[0].second;
                
        for(int i=1;i<n;i++){
            while(!st.empty() && times[i].second>=times[st.top()].second){
                st.pop();
            }
            st.push(i);
        }
        return st.size();
    }
};
