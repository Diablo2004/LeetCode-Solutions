class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int i=0;
        int n=points.size();
        int ans=1;
        while(i<n-1){
            if(points[i][1]>=points[i+1][0]){
                points[i+1][1]=min(points[i][1],points[i+1][1]);
                
            }else{
                ans++;
            }
            
            i++;            
        }
        return ans;
    }
};