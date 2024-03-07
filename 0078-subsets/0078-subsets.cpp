class Solution {
private:
    void sub(vector<int> nums,int index,vector<int>& result,vector<vector<int>>& ans){
        if(index>=nums.size()){
            ans.push_back(result);
            return;
        }
        sub(nums,index+1,result,ans);
        result.push_back(nums[index]);
        sub(nums,index+1,result,ans);
        result.pop_back();
    }
        
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> result;
        vector<vector<int>> ans;
        int index=0;
        sub(nums,index,result,ans);
        return ans;
    }
};