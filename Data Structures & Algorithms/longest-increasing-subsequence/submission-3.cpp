class Solution {
public:
    int n=0;
    vector<int>dp;
    int rec(int i,vector<int>&nums){
        //prunning

        //basecase
        if(i==n)
            return 0;
        //cache check
        if(dp[i]!=-1){
            return dp[i];
        }

        //transition
        int ans=1;
        for(int j=i+1;j<n;j++){
            if(nums[j]>nums[i])
                ans=max(ans,1+rec(j,nums));
        }
        dp[i]=ans;

        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        dp.assign(n+1,-1);
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,rec(i,nums));
        }
        return ans;
    }
};
