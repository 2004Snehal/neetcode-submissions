class Solution {
public:
    int INF=1000;

    int maxProduct(vector<int>& nums) {
        int curmax=nums[0];
        int curmin=nums[0];
        int ans=nums[0];
        // int curmin2=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            int x=nums[i];

            int lcmax=curmax;
            curmax=max({x,lcmax*x,curmin*x});
            int lcmin=curmin;
            curmin=min({x,lcmin*x,lcmax*x});
            
            // if(x!=1){
            //     if(lcmax==curmax||lcmin==curmin){
            //         curmax=x;
            //         curmin=x;
            //     }
                
                    
            // }
            ans=max(ans,curmax);
            cout<<curmax<<" "<<curmin<<endl;
        }

        return ans;
    }
};
