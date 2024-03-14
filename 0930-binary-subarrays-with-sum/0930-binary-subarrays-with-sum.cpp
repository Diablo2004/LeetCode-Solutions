class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        int sum = 0;
        int left = 0;
        if (goal == 0) {
            int zeroCount = 0;
            for (int num : nums) {
                if (num == 0)
                    zeroCount++;
                else {
                    count += (zeroCount * (zeroCount + 1)) / 2;
                    zeroCount = 0;
                }
            }
            count += (zeroCount * (zeroCount + 1)) / 2;
            return count;
        }
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (left <= right && sum > goal) {
                sum -= nums[left];
                left++;
            }

            if (sum == goal) {
                count++;
                int temp = left;
                while (temp < right && nums[temp] == 0) {
                    count++;
                    temp++;
                }
            }
        }

        return count;
    }
};