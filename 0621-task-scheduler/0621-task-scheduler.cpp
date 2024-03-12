class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> map;
        for(char c:tasks){
            map[c]++;
        }
        priority_queue<int> pq;
        for(auto c:map){
            pq.push(c.second);
        }
        int result=0;
        while(!pq.empty()){
            int time=0;
            vector<int> temp;
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                }
            }
            for(auto t:temp){
                if(t)
                    pq.push(t);                
            }
            result+=pq.empty()?time:n+1;
        }
        return result;
    }
};