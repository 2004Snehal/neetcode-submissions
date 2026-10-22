class Solution {
public:
    string S,P;
    vector<vector<int>>dp;
    int n,m;
    int rec(int i,int j){
    if(j==m) return i==n;                                      // only j gives a verdict
    if(dp[i][j]!=-1) return dp[i][j];

    if(j+1<m && P[j+1]=='*') return dp[i][j] = rec(i,j+1);     // starred group → defer to '*'

    int ans=0;
    if(i<n && (S[i]==P[j]||P[j]=='.')){                        // mandatory char
        ans=rec(i+1,j+1);
    } else if(P[j]=='*'){                                      // on the '*'
        if(j-1>=0){
            ans=rec(i,j+1);                                    // zero more
            if(i<n && (P[j-1]==S[i]||P[j-1]=='.'))
                ans = ans || rec(i+1,j);                       // one more
        }
    }
    return dp[i][j]=ans;
}
    bool isMatch(string s, string p) {
        S=s;
        P=p;
        dp.assign(21,vector<int>(21,-1));

        n=s.size();
        m=p.size();

        return rec(0,0);

    }
};

