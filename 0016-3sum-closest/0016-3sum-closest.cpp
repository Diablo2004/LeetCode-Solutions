class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0;
        int closest=INT_MAX-abs(target);
        int left,right;
        int n=nums.size();
        for(int i=0;i<n;i++){
            left=i+1;
            right=n-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum>target){
                    right--;
                }else if(sum<target){
                    left++;
                }else {
                    return target;
                }
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum; 
                }
            }
        }
        return closest;
    }
};