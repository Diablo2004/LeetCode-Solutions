class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> result;
        
        for(char a:magazine){
            result[a]++;
        }
        for(char c:ransomNote){
            result[c]--;
        }
        for(auto & pair : result){
            if(pair.second<0){
                return false;
            }
        }
        return true;
    }
};