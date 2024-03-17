class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        int current=1;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            if (map.find(nums[i]) == map.end()) { 
                map[nums[i]] = 1;  
            }
        }
        for (int num : nums) {
            if (map.find(num - 1) == map.end()) {
                int currentNum = num;
                while (map.find(currentNum + 1) != map.end()) {
                    currentNum++;
                    current++;
                }
                ans = std::max(ans, current);
                current = 1;
            }
        }
        return ans;

    }
};