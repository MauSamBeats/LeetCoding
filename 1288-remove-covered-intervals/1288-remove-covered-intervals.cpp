class Solution {
public:
    struct compare{
        bool operator()(vector<int>& a, vector<int>& b){
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]>b[1];
        }
    };
    int removeCoveredIntervals(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),compare());
        int ans=0, idx=0;
        for(int i=1; i<v.size(); i++){
            if(v[idx][1]>=v[i][1]) ans++;
            else idx=i;
        }
        return v.size()-ans;
    }
};