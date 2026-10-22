class Solution {
public:
    int n,m;
    string w1,w2;
    vector<vector<int>>dp;
    int rec(int i,int j){
        //base case
        if(i==n && j==m) return 0;
            if(i==n) return m-j;   // insert remaining word2 chars
            if(j==m) return n-i;   // delete remaining word1 chars
        //cache chek
        if(dp[i][j]!=-1)
            return dp[i][j];
        //transition
        int ans=0;

        if(w1[i]==w2[j])
            if(i<n)
                ans=rec(i+1,j+1);
            else
                ans=rec(i,j+1);
        else
            {
                if(i<n)
                    ans=min({1+rec(i+1,j),1+rec(i+1,j+1),1+rec(i,j+1)});
                else
                    ans=1+rec(i,j+1);
            }
        //save and return
        dp[i][j]=ans;
        return ans;

    }
    int minDistance(string word1, string word2) {
        w1=word1;
        w2=word2;
        n=w1.size();
        m=w2.size();

        dp.assign(101,vector<int>(101,-1));
        return rec(0,0);
    }
};
