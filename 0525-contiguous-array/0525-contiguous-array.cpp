class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans=0;
        int sum=0;
        unordered_map<int,int> map;
        map[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                sum+=-1;
            }
            else{
                sum+=1;
            }
            if(map.find(sum)!=map.end()){
                ans=max(ans,i-map[sum]);
                continue;
            }else{
                map[sum]=i;
            }
        }
        return ans;
    }
};