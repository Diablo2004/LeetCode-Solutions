class Solution {
private:
    void permuteHelper(vector<int> nums,vector<int>& result,vector<vector<int>>& ans,vector<bool>& freq){
        if(result.size()==nums.size()){
            ans.push_back(result);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i]=true;
                result.push_back(nums[i]);
                permuteHelper(nums,result,ans,freq);
                result.pop_back();
                freq[i]=false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> result;
        vector<vector<int>> ans;
        vector<bool> freq(nums.size(), false);
        permuteHelper(nums,result,ans,freq);
        return ans;
    }
};