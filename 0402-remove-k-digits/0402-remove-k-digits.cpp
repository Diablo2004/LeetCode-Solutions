class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;

        for (char digit : num) {
            while (k > 0 && !result.empty() && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }

        result.resize(result.size() - k);  // Remove remaining k digits

        // Remove leading zeros
        size_t i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }
        result = result.substr(i);

        // Handle the case where result is empty
        if (result.empty()) {
            result = "0";
        }

        return result;
    }
};