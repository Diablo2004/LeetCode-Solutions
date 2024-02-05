class Solution {
public:
    bool isValid(string s) {
        stack <int> st;
        for(int i=0;i<s.length();i++){
            if(s.at(i)=='(' or s.at(i)=='[' or s.at(i)=='{'){
                st.push(s.at(i));
            }
            else{
                if (st.empty()) return false;
                char c=st.top();
                st.pop();
                if((s.at(i)==')' && c=='(') || (s.at(i)== ']' && c=='[') || (s.at(i)=='}' && c=='{')  ){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};