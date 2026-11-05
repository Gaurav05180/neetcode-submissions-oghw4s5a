class Solution {
public:

    int fun(int i, vector<int>& nums, vector<int>& dp){
        if(i>=nums.size()) return 0;

        if(dp[i]!=-1) return dp[i];

        return dp[i] = max(nums[i]+fun(i+2, nums, dp), fun(i+1, nums, dp));
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return fun(0, nums, dp);
    }
};
