class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int rec(int i,int j,vector<vector<int>>& matrix){
        //prunning
        if(i<0||i>n||j<0||j>m)
            return 0;
        //base cacse
        if(i==n||j==m)
            return 0;
        //cache chek
        if(dp[i][j]!=-1)
            return dp[i][j];
        //transition
        int ans=1;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};

        for(int dir=0;dir<4;dir++){
            int x=i+dx[dir];
            int y=j+dy[dir];
            if(x<0||x>=n||y<0||y>=m)
                ans+=0;
            else
                if (matrix[x][y] > matrix[i][j])
                    ans = max(ans, 1 + rec(x, y,matrix));
        }
        //save and return
        dp[i][j]=ans;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();

        dp.assign(101,vector<int>(101,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,rec(i,j,matrix));
            }
        }
        return ans;
    }
};
