class Solution {
private:
    string convertBinary(int decimal){
        string binary = ""; 
        while (decimal > 0) {
            binary =to_string(decimal % 2) + binary;

            decimal /= 2;
        }
        if (binary == "") {
            binary = "0";
        }

        return binary;
    }
    
public:
    vector<int> countBits(int n) {
        vector<int> arr;
        vector<string> temp;
        for(int i=0;i<=n;i++){
            string x=convertBinary(i);
            temp.push_back(x);
        }
        for(const string&str:temp){
            int a=0;
            for(char c: str){
                if(c=='1'){
                    a++;
                }
            }
            arr.push_back(a);
        }

        return arr;
    }
};