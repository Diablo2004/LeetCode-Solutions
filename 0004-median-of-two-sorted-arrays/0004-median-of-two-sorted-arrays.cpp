class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int x:nums1) ans.push_back(x);
        for(int y:nums2) ans.push_back(y);
        sort(ans.begin(),ans.end());
        int n=ans.size();
        return n%2?ans[n/2]:(ans[n/2 -1]+ans[n/2])/2.0;
    }
};