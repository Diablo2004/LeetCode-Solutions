class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> nums;
        for (int asteroid : asteroids) {
            if (st.empty() || asteroid > 0) {
                st.push(asteroid);
            } else {
                while (!st.empty() && st.top() > 0 && st.top() < abs(asteroid)) {
                    st.pop();  
                }
                if (st.empty() || st.top() < 0) {
                    st.push(asteroid);  
                } else if (st.top() == abs(asteroid)) {
                    st.pop();  
                }
            }
        }
        while(!st.empty()){
            nums.push_back(st.top());
            st.pop();
        }
        reverse(nums.begin(),nums.end());
        return nums;
    }
};