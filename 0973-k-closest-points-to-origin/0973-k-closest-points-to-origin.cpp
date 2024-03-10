class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
       vector<pair<int, vector<int>>> v; 
        for(int i = 0; i < points.size(); i++){
            int s = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            v.push_back({s, {points[i][0],points[i][1]}});
        }
        sort(v.begin(), v.end());
        int j = 0;
        while(k-- > 0 ){
            ans.push_back(v[j++].second);
        }

       return ans; 
    }
};