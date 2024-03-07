class Solution {
private:
    const vector<string> mappings = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(string digits,int index,string current,vector<string>& result){
        if(index==digits.length()){
            result.push_back(current);
            return;                
        }
        int digit=digits[index]-'0';
        for(char c:mappings[digit]){
            current.push_back(c);
            helper(digits, index + 1, current, result);
            current.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        helper(digits,0,"",result);
        return result;
    }
};