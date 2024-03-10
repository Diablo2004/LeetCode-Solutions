class Solution {
private:
    void helper(vector<string>& res,int lc,int rc,string& current,int n){
        if (current.length()==n*2){
            res.push_back(current);
            return;
        }
        if(lc<n){
            current+='(';
            helper(res,lc+1,rc,current,n);
            current.pop_back();
        }
        if(rc<lc){
            current+=')';
            helper(res,lc,rc+1,current,n);
            current.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        int lc=0;
        int rc=0;
        string current="";
        vector<string> res;
        helper(res,lc,rc,current,n);
        return res;
        
    }
};