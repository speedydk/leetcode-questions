class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>>res;
        vector<vector<string>>ans;
        
        for(auto it: strs)
        {
            string id ="";
            vector<int>arr(26,0);
            for(int i = 0; i<it.size(); i++)
                arr[it[i] - 'a']++;
            
            for(int i = 0; i<26; i++)
                id += to_string(arr[i]) + "$";
            
            res[id].push_back(it);
        }
        
        for(auto it=res.begin(); it!=res.end(); it++)
            ans.push_back(it->second);
        
        return ans;
    }
};