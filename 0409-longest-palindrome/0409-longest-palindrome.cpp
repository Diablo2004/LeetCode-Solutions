class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;
        
        int length = 0;
        bool hasOdd = false;
        
        for (const auto& entry : freq) {
            length += entry.second / 2 * 2;
            if (entry.second % 2 == 1)
                hasOdd = true;
        }
        
        return length + (hasOdd ? 1 : 0);
    
    }
};