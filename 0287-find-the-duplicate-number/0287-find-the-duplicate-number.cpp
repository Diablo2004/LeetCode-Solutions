class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate = 0;
        for (int bit = 0; bit < 32; ++bit) {
            int mask = 1 << bit;
            int count1 = 0, count2 = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] & mask) {
                    count1++;
                }
                if (i & mask) {
                    count2++;
                }
            }
            if (count1 > count2) {
                duplicate |= mask;
            }
        }
        return duplicate;
    }
    
};