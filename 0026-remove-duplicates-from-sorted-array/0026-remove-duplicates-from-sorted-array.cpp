class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        int index=0;
        for(int num:nums){
            if(mp.find(num)==mp.end()){
                mp[num]++;
                nums[index++]=num;
            }
        }
        return mp.size();
    }
};