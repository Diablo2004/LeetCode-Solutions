class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(int i=0;i<strs.size();i++){
            string word=strs[i];
            string key=strs[i];
            sort(key.begin(),key.end());
            if(map.find(key)==map.end()){
                map[key]={word};
            }else{
                map[key].push_back(word);
            }
        }
        vector<vector<string>> ans;
        for(auto str:map){
            ans.push_back(str.second);
        }
        return ans;
    }
};