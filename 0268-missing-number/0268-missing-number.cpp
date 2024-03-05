class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=nums.size();
        int y=0;
        for(int i=0;i<=x;i++){
            y=y+i;
        }
        for(int i=0;i<nums.size();i++){
            y-=nums[i];
        }
        return y;
    }
};