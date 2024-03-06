class Solution {
public:
    int reverse(int x) {
        int answer=0;
        int value=0;
        if(x<0){
            value=1;
        }
        x=abs(x);
        while(x>0){
            if (answer > INT_MAX / 10)
                return 0;
            answer=answer*10+(x%10);
            x/=10;
        }
        if(value==1){
            answer*=-1;
        }
        return answer;
    }
};