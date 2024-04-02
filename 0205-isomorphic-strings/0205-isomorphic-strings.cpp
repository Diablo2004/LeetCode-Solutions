class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> mapping;

        for (int i = 0; i < s.length(); ++i) {
            char char_s = s[i];
            char char_t = t[i];

            if (mapping.find(char_s) != mapping.end()) {
                if (mapping[char_s] != char_t) {
                    return false;
                }
            } else {
                for (const auto& pair : mapping) {
                    if (pair.second == char_t) {
                        return false;
                    }
                }
                mapping[char_s] = char_t;
            }
        }

        return true;
    }
};