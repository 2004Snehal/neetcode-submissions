class Solution {
public:
    vector<vector<int>> dp;
    string t1, t2, t3;

    int rec(int i, int j) {
        //base case
        if (i == 0 && j == 0)
            return 1;
        //cache chek
        if (dp[i][j] != -1)
            return dp[i][j];
        //transition
        int ans = 0;
        if (i > 0 && t1[i-1] == t3[i+j-1])
            ans = ans || rec(i-1, j);
        if (j > 0 && t2[j-1] == t3[i+j-1])
            ans = ans || rec(i, j-1);

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        t1 = s1; t2 = s2; t3 = s3;
        dp.assign(101, vector<int>(101, -1));
        return rec(s1.size(), s2.size());
    }
};