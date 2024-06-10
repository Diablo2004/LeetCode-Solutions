class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<triangle[i].size();j++){
                if(i==0 && j==0) dp[i][j]=triangle[i][j];
                else if(j==0){
                    dp[i][j]=dp[i-1][0]+triangle[i][j];
                }else if(i<=j){
                    dp[i][j]=dp[i-1][j-1]+triangle[i][j];
                }else{
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[m-1][i]);
        }
        return ans;
    }
};