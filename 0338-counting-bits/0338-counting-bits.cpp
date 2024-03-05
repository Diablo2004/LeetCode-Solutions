class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1);
        
        for (int i = 0; i <= n; ++i) {
            int count = 0;
            int num = i;
            while (num > 0) {
                count += num & 1;
                num >>= 1;
            }
            result[i] = count;
        }
        
        return result;
    }
};