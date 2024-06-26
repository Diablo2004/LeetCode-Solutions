class Solution {

public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int curr=0;
        int prev1=1;
        int prev2=1;
        for(int i=2;i<n+1;i++){
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};