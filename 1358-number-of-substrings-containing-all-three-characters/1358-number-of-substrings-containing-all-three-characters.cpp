class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        vector<int> v(3,-1);
        for(int i=0; i<s.size(); i++){
            v[s[i]-'a']=i;
            int earliest = *min_element(v.begin(),v.end());
            if(earliest!=-1) ans+=earliest+1;
        }
        return ans;
    }
};