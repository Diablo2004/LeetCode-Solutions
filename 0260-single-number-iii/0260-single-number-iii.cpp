class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        if (nums.size() == 1) {
            ans.push_back(nums[0]);
            return ans;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i]){
                i++;
            }else{
                ans.push_back(nums[i]);
            }
        }
        if (nums[nums.size() - 1] != nums[nums.size() - 2]) {
            ans.push_back(nums[nums.size() - 1]);
        }
        return ans;
    }
};