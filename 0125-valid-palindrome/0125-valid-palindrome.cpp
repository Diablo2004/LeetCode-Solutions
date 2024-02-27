class Solution {
public:
    bool isPalindrome(string s) {
        string cleanString;
        for (char c : s) {
            if (isalnum(c)) {
                cleanString += tolower(c);
            }
        }
        
        int left = 0, right = cleanString.length() - 1;
        while (left < right) {
            if (cleanString[left] != cleanString[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};