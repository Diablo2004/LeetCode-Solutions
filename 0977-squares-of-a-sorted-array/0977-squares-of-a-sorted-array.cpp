class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {\
        int index=0;
        for(int num:nums){
            nums[index++]=num*num;
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};