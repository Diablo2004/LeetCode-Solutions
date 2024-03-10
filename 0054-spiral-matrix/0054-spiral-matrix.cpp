class Solution {  
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};

        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> res;

        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++) {
                if (!visited[top][j]) {
                    res.push_back(matrix[top][j]);
                    visited[top][j] = true;
                }
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                if (!visited[i][right]) {
                    res.push_back(matrix[i][right]);
                    visited[i][right] = true;
                }
            }
            right--;

            for (int j = right; j >= left; j--) {
                if (!visited[bottom][j]) {
                    res.push_back(matrix[bottom][j]);
                    visited[bottom][j] = true;
                }
            }
            bottom--;
            for (int i = bottom; i >= top; i--) {
                if (!visited[i][left]) {
                    res.push_back(matrix[i][left]);
                    visited[i][left] = true;
                }
            }
            left++;
        }

        return res;
    }
};