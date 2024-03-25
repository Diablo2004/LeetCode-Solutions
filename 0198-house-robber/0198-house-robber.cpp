class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1){
            return nums[0];
        }
        if(n==2) return max(nums[0],nums[1]);
        int dp[++n];
        dp[0]=0;
        dp[1]=nums[0];
        dp[2]=nums[1];
        int ans=max(dp[1],dp[2]);
        for(int i=3;i<n;i++){
            dp[i]=max(nums[i-1]+dp[i-2],nums[i-1]+dp[i-3]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};