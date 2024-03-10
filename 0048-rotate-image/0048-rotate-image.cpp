class Solution {
private:
    
    void reverseRows(vector<vector<int>>& matrix) {
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1 - i; ++j) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        reverseRows(matrix);
        transpose(matrix);
    }
};