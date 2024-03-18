class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int i=0;
        while(i<n-1){
            if(intervals[i][1]>=intervals[i+1][1]){
                ans++;
            }
            else if (intervals[i+1][0]<intervals[i][1] && intervals[i][1]<intervals[i+1][1]){
                intervals[i+1]=intervals[i];
                ans++;
            }
            i++;
        }
        return ans;
    }
};