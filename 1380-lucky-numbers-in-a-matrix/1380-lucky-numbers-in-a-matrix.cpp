class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int rminmax=INT_MIN;
        for(int i=0;i<n;i++){
            int rmin=INT_MAX;
            for(int j=0;j<m;j++){
                rmin=min(rmin,matrix[i][j]);
            }
            rminmax=max(rmin,rminmax);
        }
        
        int cmaxmin=INT_MAX;
        for(int j=0;j<m;j++){
            int cmax=INT_MIN;
            for(int i=0;i<n;i++){
                cmax=max(cmax,matrix[i][j]);
            }
            cmaxmin=min(cmax,cmaxmin);
        }
        if(rminmax==cmaxmin){
            return {rminmax};
        }
        return {};
    }
};