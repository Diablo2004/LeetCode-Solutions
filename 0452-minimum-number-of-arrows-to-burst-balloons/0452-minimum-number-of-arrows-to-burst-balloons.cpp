class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<vector<int>> ans;
        int i=0;
        int n=points.size();
        while(i<n-1){
            if(points[i][1]>=points[i+1][0]){
                points[i+1][1]=min(points[i][1],points[i+1][1]);
                
            }else{
                ans.push_back(points[i]);
            }
            
            i++;
            
        }
        ans.push_back(points[i]);
        return ans.size();
    }
};