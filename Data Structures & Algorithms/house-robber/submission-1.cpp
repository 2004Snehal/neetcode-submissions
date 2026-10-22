class Solution {
public:
    int dp[1001];

    int rec(int i,vector<int>& nums,int n){
    //basecase
    if(i >= n){
        return 0;
    }
    //cache check
    if(dp[i]!=-1){//dekh ho ki ye value pehele calculate kiya ki nahi
        return dp[i];
    }
    //transition
    int ans=nums[i];
    ans+=max(rec(i+2,nums,n),rec(i+3,nums,n));
    //save and return
    dp[i]=ans;

    return ans;
    }
    int rob(vector<int>& nums) {
        fill(dp, dp + 1001, -1);
        int n=nums.size();
        return max(rec(0, nums, n), rec(1, nums, n));
    }
};
