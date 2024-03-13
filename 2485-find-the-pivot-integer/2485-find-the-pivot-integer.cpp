class Solution {
public:
    int pivotInteger(int n) {
        int pivot=-1;
        if(n==1){
            return 1;
        }
        for(int i=0;i<n;i++){
            if((i*(i+1)/2)==n*(n+1)/2-(i*(i+1)/2)+i){
                pivot=i;
            }                         
        }
        return pivot;
    }
};