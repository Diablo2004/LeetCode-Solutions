class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return processString(s)==processString(t);
    };
    
    private:
        string processString(string s){
        stack<char> result;
        for(int i=0;i<s.length();i++){
            if(s.at(i)!='#'){
                result.push(s.at(i));            
            }
            else if(!result.empty()){
                result.pop();
            }                
        }
            string x;
        while(!result.empty()){
            x+=result.top();
            result.pop();
        }
        reverse(x.begin(),x.end());
        return x;
        }
    
    
};