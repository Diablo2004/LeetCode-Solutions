class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int tempSum=0;
        int index;
        int currentSum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1] && nums[i]==0) return true;
            currentSum+=nums[i];
            if(currentSum % k==0) return true;
            index=0;
            tempSum=currentSum;
            while((i-index)>1 && tempSum>=k){
                tempSum-=nums[index++];
                if(tempSum%k==0) return true;
            }
        }
        return false;
    }
};