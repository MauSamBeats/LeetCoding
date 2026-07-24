class Solution {
public:
    int uniqueXorTriplets(vector<int>& v) {
        vector<int> has(2048,0);
        for(int i=0; i<v.size(); i++){
            for(int j=i; j<v.size(); j++){
                has[v[i]^v[j]]=1;
            }
        }
        vector<int> ans_has(2048,0);
        for(int i=0; i<has.size(); i++){
            if(has[i]){
                for(int j=0; j<v.size(); j++){
                    ans_has[i^v[j]]=1;
                }
            }
        }
        int ans=0;
        for(int i=0; i<has.size(); i++){
            if(ans_has[i]) ans++;
        }
        return ans;
    }
};