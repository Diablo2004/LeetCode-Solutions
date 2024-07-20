class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size();
        int m=colSum.size();
        vector<vector<int>> mat(n,vector<int>(m,0));
        int i=n-1,j=m-1;
        while(i>=0 && j>=0){
            if(rowSum[i]<=colSum[j]){
                mat[i][j]=rowSum[i];
                colSum[j]-=rowSum[i];
                i--;
            }else{
                mat[i][j]=colSum[j];
                rowSum[i]-=colSum[j];
                j--;
            }
        }
        return mat;
    }
};