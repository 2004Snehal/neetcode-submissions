#include <cstring>

class Solution {
public:
    int x;
    int n;
    int offset=1000;
    int dp[2002][1001];
    int rec(int s,int i,vector<int>& nums){
        //base case
        if(i==n)
            if(s!=x)
                return 0;
            else
                return 1;
        
        //cache chek
        if(dp[s+offset][i]!=-1){
            return dp[s+offset][i];
        }
        //transition
        int ans=0;

        ans += rec(s-nums[i],i+1, nums);
        ans += rec(s+nums[i],i+1, nums);    

        //save and return 
        dp[s+offset][i]=ans;

        return dp[s+offset][i];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        x=target;
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,nums);
    }
};
