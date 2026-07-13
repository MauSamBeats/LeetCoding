class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v(arr);
        sort(v.begin(),v.end());
        unordered_map<int,int> mp;
        int curr = 1;
        for(int i=0; i<v.size(); i++){
            if(i!=0 && v[i]==v[i-1]) continue;
            mp[v[i]]=curr++;
        }
        vector<int> ans;
        for(int i=0; i<arr.size(); i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};