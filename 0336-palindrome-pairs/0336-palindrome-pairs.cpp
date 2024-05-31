class Solution {
public:
    bool isPalindrome(const string& s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> wordMap;
        
        // Populate the map with reversed words
        for (int i = 0; i < words.size(); ++i) {
            string reversedWord = words[i];
            reverse(reversedWord.begin(), reversedWord.end());
            wordMap[reversedWord] = i;
        }

        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            for (int j = 0; j <= word.length(); ++j) {
                // Split the word into two parts
                string left = word.substr(0, j);
                string right = word.substr(j);
                
                // Check if the left part is a palindrome and the reversed right part exists in the map
                if (isPalindrome(left) && wordMap.find(right) != wordMap.end() && wordMap[right] != i) {
                    result.push_back({wordMap[right], i});
                }
                
                // Check if the right part is a palindrome and the reversed left part exists in the map
                if (!right.empty() && isPalindrome(right) && wordMap.find(left) != wordMap.end() && wordMap[left] != i) {
                    result.push_back({i, wordMap[left]});
                }
            }
        }

        return result;
    }
};
