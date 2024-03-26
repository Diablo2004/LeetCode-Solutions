class Solution {
private:
    int help(int index,int prev,vector<int>& nums,int n,vector<vector<int>>& dp){
        if(index==n) return 0;
        if(dp[index][prev+1] !=-1) return dp[index][prev+1];
        int len=0+help(index+1,prev,nums,n,dp);
        if(prev==-1 || nums[index]>nums[prev]){
            len=max(len,1+help(index+1,index,nums,n,dp));
        }
        return dp[index][prev+1]=len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1,-1));
        return help(0,-1,nums,nums.size(),dp);
    }
};