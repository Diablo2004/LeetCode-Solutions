
class Solution {
private:
    vector<int> prefixSum;
    mt19937 rng;

public:
    Solution(vector<int>& nums) {
        int sum = 0;
        for (int weight : nums) {
            sum += weight;
            prefixSum.push_back(sum);
        }
        
        random_device rd;
        rng.seed(rd());
    }
    
    int pickIndex() {
        int target = rng() % prefixSum.back();
        
        int left = 0, right = prefixSum.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefixSum[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }
};
