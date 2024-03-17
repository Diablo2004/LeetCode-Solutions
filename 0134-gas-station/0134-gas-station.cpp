class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;
        int ptr=0;
        int total=0;
        for(int i=0;i<gas.size();i++){
            sum+=gas[i]-cost[i];
            total+=gas[i]-cost[i];
            if(sum<0){
                sum=0;
                ptr=i+1;
            }
        }
        if(ptr==gas.size() || total<0){
            return -1;
        }
        return ptr;
    }
};