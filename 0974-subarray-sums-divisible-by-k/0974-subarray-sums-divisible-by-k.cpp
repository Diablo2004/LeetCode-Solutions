class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0]++;
        int sum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            sum=(sum+nums[i])%k;
            if(sum<0) sum+=k;
            if(map.find(sum)!=map.end()){
                cnt+=map[sum];
            }
            map[sum]++;
        }
        
    return cnt;
    }
};