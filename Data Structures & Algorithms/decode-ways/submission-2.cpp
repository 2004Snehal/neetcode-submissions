class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> memo(n, -1);
        return dfs(0, n, s, memo);
    }

    int dfs(int i, int n, string& s, vector<int>& memo) {
        if (i == n)
            return 1;
        if (s[i] == '0')
            return 0;
        if (memo[i] != -1)
            return memo[i];

        int ways = dfs(i + 1, n, s, memo);
        if (i + 1 < n && stoi(s.substr(i, 2)) <= 26) {
            ways += dfs(i + 2, n, s, memo);
        }

        memo[i] = ways;
        return ways;
    }
};