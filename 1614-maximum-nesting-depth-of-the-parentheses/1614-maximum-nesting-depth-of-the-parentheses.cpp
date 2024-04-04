class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int current=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                current++;
                ans=max(ans,current);
            }else if(s[i]==')'){
                current--;
            }
            
        }
        return ans;
    }
};