class Solution {
public:
    int n;
    vector<int> dp;
    const int INF = 1e9;

    int rec(int rem,vector<int>&coins){
        //prunning if rem is negative then invalid
        if(rem<0) 
            return INF;
        //base case check
        if(!rem){
            return 0;
        }

        //cache check
        if(dp[rem]!=-1){
            return dp[rem];
        }
        //transition
        int ans = INF;
        for(int i=0;i<n;i++){
            ans=min(ans,1+rec(rem-coins[i],coins));
        }
        dp[rem]=ans;

        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();

        dp.assign(amount+1,-1);

        int ans=rec(amount,coins);
        if(ans!=INF)
            return ans;
        return -1;
    }
};
