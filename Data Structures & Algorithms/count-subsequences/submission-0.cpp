class Solution {
public:
    int n,m;
    string s1,s2;
    vector<vector<int>>dp;
    int rec(int i,int j){
        //pruning
        if(i>=n && j<m)
            return 0;
        //base 
        if(j>=m){
            return 1;
        }
        //cache chek
        if(dp[i][j]!=-1)
            return dp[i][j];
        //transition
        int ans=0;
            if(s1[i]==s2[j]){
                ans+=(rec(i+1,j+1)+rec(i+1,j));
            }
            else
                ans+=rec(i+1,j);
        //save and return
        dp[i][j]=ans;

        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        s1=s;
        s2=t;
        n=s1.size();
        m=s2.size();

        dp.assign(1001,vector<int>(1001,-1));

        return rec(0,0);
    }
};
