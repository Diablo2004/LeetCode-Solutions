class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int current=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            auto it = map.find(s[i]);
            if(it==map.end() || it->second < i - current){
                current++;
            }else{
                current=i-it->second;
            }
            map[c]=i;
            ans=max(ans,current);
        }
        return ans;
    }
};