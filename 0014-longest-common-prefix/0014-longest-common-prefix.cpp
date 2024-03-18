class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         if (strs.empty()) {
             return "";
        }
        string prefix=strs[0];
        
        for(int i=1;i<strs.size();i++){
            int count=0;
            int j=0;
            while(j < strs[i].size() && prefix[j]==strs[i].at(j)){
                count++;
                j++;
            }
            prefix=prefix.substr(0,count);
                
        }
        return prefix;
    }
};