class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto c:nums){
            map[c]++;
        }
        for(auto c:map){
            if(c.second>1){
                return true;
            }
        }
        return false;
    }
};