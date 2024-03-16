class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> x(n, 1);
        vector<int> y(n, 1);
        vector<int> ans(n, 0);
        for (int i = 1; i < n; i++) {
            x[i] = x[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            y[i] = y[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; i++) {
            ans[i] = x[i] * y[i];
        }

        return ans;
    }
};