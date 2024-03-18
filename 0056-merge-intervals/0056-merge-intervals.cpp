class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int i=0;
        int n=intervals.size();
        while(i<n-1){
            if(intervals[i][1]>=intervals[i+1][0]){
                intervals[i+1][0]=intervals[i][0];
                intervals[i+1][1]=max(intervals[i][1],intervals[i+1][1]);
            }else{
                ans.push_back(intervals[i]);
            }
            i++;
        }
        ans.push_back(intervals[i]);
        return ans;
    }
};