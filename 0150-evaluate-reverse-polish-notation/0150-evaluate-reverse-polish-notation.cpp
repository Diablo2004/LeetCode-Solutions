class Solution {
private:
    bool isOperator(const string& token){
         return token=="+" || token=="-" || token=="*" || token=="/";
     }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> rpn;
        
        for(const auto& token:tokens){
            if(isOperator(token)){
                int op1=rpn.top();
                rpn.pop();
                int op2=rpn.top();
                rpn.pop();
                int result;
                
                if(token=="+"){
                    result= op1+op2;
                }
                else if(token=="-"){
                    result= op2-op1;
                }
                else if(token=="*"){
                    result= op1*op2;
                }
                else if(token=="/"){
                    if (op1 == 0) {
                        throw runtime_error("Division by zero");
                    }
                    result= op2/op1;
                }
                rpn.push(result);
            }
            else{
                rpn.push(stoi(token));
            }
        }
        return rpn.top();
    }
    
};