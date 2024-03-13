class Solution {
public:
    int pivotInteger(int n) {
        
        if(n==1){
            return 1;
        }
        double x=sqrt(n*(n+1)/2);
        if(fmod(x,1.0)!=0){
            return -1;
        }
        return static_cast<int>(x);
    }
};