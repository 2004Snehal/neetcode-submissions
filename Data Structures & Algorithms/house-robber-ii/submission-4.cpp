class Solution {
public:
    int dp[2][1001];
    int rec(int i, vector<int>& nums, int n, int r) {
        if (i == r) return 0;
        if (i >= n) return 0;

        int cached = (r == -1) ? dp[0][i] : dp[1][i];
        if (cached != -1) return cached;

        int ans = max(nums[i] + rec(i+2, nums, n, r),   // take current
                                  rec(i+1, nums, n, r)); // skip current

        if (r == -1) dp[0][i] = ans;
        else         dp[1][i] = ans;

        return ans;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        fill(dp[0], dp[0]+1001, -1);
        fill(dp[1], dp[1]+1001, -1);

        int case1 = rec(0, nums, n, n-1);  // start 0, last house blocked
        int case2 = rec(1, nums, n, -1);   // start 1, no restriction

        return max(case1, case2);
    }
};