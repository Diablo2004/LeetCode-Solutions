class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        int n = s.size();
        
        // Start from the end of the string
        for (int i = n - 1; i > 0; --i) {
            int digit = s[i] - '0' + carry;
            if (digit == 1) {
                carry = 1;  // Set carry if the current digit is 1
                steps += 2; // Increment steps by 2 (add 1 and divide by 2)
            } else {
                steps += 1; // Increment steps by 1 (divide by 2)
            }
        }
        
        // Add final step if there's a carry at the beginning
        if (carry == 1) {
            steps += 1;
        }
        
        return steps;
    }
};