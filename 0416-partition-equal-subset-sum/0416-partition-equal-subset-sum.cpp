class Solution {

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return false;

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;  

        int targetSum = totalSum / 2;
        vector<bool> dp(targetSum + 1, false);
        dp[0] = true; 

        for (int num : nums) {
            for (int j = targetSum; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[targetSum];
    }
};