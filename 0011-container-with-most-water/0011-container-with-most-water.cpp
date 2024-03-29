class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int ans=0;
        while(left<right){
            int area=(right-left)*min(height[left],height[right]);
            ans=max(area,ans);
            height[left]>height[right] ? right-- : left++;
        }
        return ans;
    }
};