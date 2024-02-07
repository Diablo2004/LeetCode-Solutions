class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int x=temperatures.size();
        vector<int>nge(x, 0);
        stack<int>st{};
        
        for(int i=x-1; i>=0;i--){
            while(!st.empty() && temperatures[st.top()] <=temperatures[i])
                st.pop();
            if(!st.empty())
                nge[i]=st.top()-i;
            st.push(i);
        }
        return nge;
    }
};