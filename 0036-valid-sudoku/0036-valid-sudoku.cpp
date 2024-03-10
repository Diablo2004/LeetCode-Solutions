class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    string x = "(" + string(1, board[i][j]) + ")";
                    if (!s.insert(x + to_string(i)).second || 
                        !s.insert(to_string(j) + x).second || 
                        !s.insert(to_string(i / 3) + x + to_string(j / 3)).second)
                        return false;
                }
            }
        }
        return true;
    }
};