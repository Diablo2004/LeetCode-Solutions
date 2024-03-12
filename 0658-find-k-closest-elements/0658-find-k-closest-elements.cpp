class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> minHeap;
        vector<int> ans;
        for(auto i:arr){
            int n=abs(x-i);
            minHeap.push({n,i});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        while(minHeap.size()>0){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};