class Solution {
void help(int start,int target,vector<int>& candidates,vector<int>& path,vector<vector<int>>& result){
    if(target==0){
        result.push_back(path);
        return;
    }
    if(target<0){
        return;
    }
    for(int i=start;i<candidates.size();i++){
        path.push_back(candidates[i]);
        help(i,target-candidates[i],candidates,path,result);
        path.pop_back();
    }
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        int start=0;
        help(start,target,candidates,path,result);
        return result;
    }
};