class Solution {
public:
    vector<vector<int>> dp;
    int rec(int x,int y,int m,int n){
        //prunning
        if(x<0||y<0||x>m||y>n){
            return 0;
        }

        //base case
        if(x==m && y==n)
            return 1;
        //cache check
        if(dp[x][y]!=-1)
            return dp[x][y];
        //transition
        
        //dp=2 directions
        int ans = rec(x + 1, y, m, n) + rec(x, y + 1, m, n);

        dp[x][y]=ans;

        return dp[x][y];

    }
    int uniquePaths(int m, int n) {
        m=m-1;
        n=n-1;//0 based indexing
        dp.assign(m + 1, vector<int>(n + 1, -1)); 

        return rec(0,0,m,n);
    }
};
