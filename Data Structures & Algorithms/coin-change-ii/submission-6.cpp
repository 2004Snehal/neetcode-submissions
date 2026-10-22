class Solution {
public:
    int tar;
    vector<vector<int>> dp;

    int rec(int i, int s, vector<int>& c){
        //pruning
        if(s > tar || i == (int)c.size())
            return 0;
        //base case
        if(s == tar)
            return 1;
        //cache check
        if(dp[i][s] != -1)
            return dp[i][s];
        //transition
        int ans = 0;
        ans += rec(i+1, s, c);       // don't use coin i anymore
        ans += rec(i, s+c[i], c);    // use coin i again (unlimited supply)

        //save and return
        dp[i][s] = ans;
        return dp[i][s];
    }

    int change(int amount, vector<int>& coins){
        tar = amount;
        dp.assign(coins.size()+1, vector<int>(tar+1, -1));

        return rec(0, 0, coins);
    }
};