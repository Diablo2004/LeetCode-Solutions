class Solution {
public:
    int lengthOfLastWord(string s) {
        int x=s.length()-1;
        while(x>=0 && s[x]==' '){
            x--;
        }
        int ans=0;
        while(x>=0 && s[x]!=' '){
            ans++;
            x--;
        }
        return ans;
    }
};