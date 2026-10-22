#include <cstring>
class Solution {

public:
    int dp[5001][3];
    int n;
    int rec(int i,int j,vector<int>& p){
        // i is the day
        // j is the sttate hold,sell,rest <=> 0,1,2

        //base case
        if(i==n)
            return 0;
        //cache chek
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //transition
        int ans=0;
        if(j==0){
            ans=max(p[i]+rec(i+1,1,p),rec(i+1,0,p));
        }
        else if(j==1){
            ans=rec(i+1,2,p);
        }
        else
            ans=max(-p[i]+rec(i+1,0,p),rec(i+1,2,p));
        //save and return
        dp[i][j]=ans;
        return dp[i][j];
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        memset(dp,-1,sizeof(dp));

        return rec(0,2,prices);

    }
};
