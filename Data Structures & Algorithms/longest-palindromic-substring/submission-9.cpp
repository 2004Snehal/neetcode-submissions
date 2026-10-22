class Solution {
    vector<vector<int>>dp;
    string s;
    int start=0;
    int maxLen=1;
public:
    string longestPalindrome(string str) {
        s=str;
        int n=str.size();
        if(n==0)
            return "";
        
        dp.assign(n,vector<int>(n,-1));

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(rec(i,j)&&j-i+1>maxLen){
                    start=i;
                    maxLen=j-i+1;
                }
            }
        }
        cout<<start<<maxLen;
        return s.substr(start,maxLen);

    }
    bool rec(int l,int r){
        //pruning

        //base case
        if(r-l+1<=1){
            return 1;
        }
        //cache chek
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        bool res=(s[l]==s[r]&&rec(l+1,r-1));

        return res;
    }
};
