#include <cstring>  
class Solution {
    
public:
    int dp[1001][1001];
    int n,m;
    int rec(int i,int j,string& s1,string& s2){
        //prunnig
        //basecase
        if(i==n||j==m){
            return 0;
        }
        //cache check
        if(dp[i][j]!=-1)
            return dp[i][j];
        //transition
        int ans=0;
        if(s1[i]==s2[j])
            ans=1+rec(i+1,j+1,s1,s2);
        else
            ans=max(rec(i+1,j,s1,s2),rec(i,j+1,s1,s2));
        //save and treturn
        dp[i][j]=ans;

        return dp[i][j];

    }
    int longestCommonSubsequence(string text1, string text2) {
        n=text1.size();
        m=text2.size();

        memset(dp, -1, sizeof(dp));

        return rec(0,0,text1,text2);
    }
};
