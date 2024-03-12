class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> map;
        for(auto c:nums){
            map[c]++;
        }
        for(auto& c:map){
            if(c.second>n/2){
                return c.first;
            }
        }
        return -1;
    }
};