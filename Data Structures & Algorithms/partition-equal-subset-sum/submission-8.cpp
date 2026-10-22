class Solution {
public:
    vector<vector<int>>dp;
    int sum=0;
    int n;
    int rec(int i,int s,vector<int>&nums){
        //prunning
        if(s>sum)
            return false;
        //basecase
        if(i==n){
            if(s==sum)
                return true;
            return false;
        }
        //cache chek
        if(dp[i][s]!=-1)
            return dp[i][s];
        //transition
        int ans=0;
        if(rec(i+1,s,nums))
            ans=1;
        if(rec(i+1,s+nums[i],nums))
            ans=1;
        //save and return
        dp[i][s]=ans;
        return dp[i][s];

    }
    bool canPartition(vector<int>& nums) {
        
        for(auto x:nums)
            sum+=x;
        if(sum%2)
            return false;
        n=nums.size();
        sum/=2;
        dp.assign(n, vector<int>(sum + 1, -1));
        
        int ans=rec(0,0,nums);
        return ans;
        
    }
};
