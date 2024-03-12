class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> numMap;
        for (int num : nums) {
            if (numMap.find(num) != numMap.end()) {
                return true;
            }
            numMap[num] = 1;
        }
        return false;
    }
};