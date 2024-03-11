class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> charIndex;
        for (int i = 0; i < order.size(); ++i) {
            charIndex[order[i]] = i;
        }
        sort(s.begin(), s.end(), [&](char a, char b) {
            return charIndex[a] < charIndex[b];
        });
        
        return s;
    }
};