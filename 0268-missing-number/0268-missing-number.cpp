class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=nums.size();
        int y=x*(x+1)/2;
        for(int i=0;i<nums.size();i++){
            y-=nums[i];
        }
        return y;
    }
};