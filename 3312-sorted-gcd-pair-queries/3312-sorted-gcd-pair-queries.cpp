class Solution {
public:
    typedef long long ll;
    vector<int> gcdValues(vector<int>& v, vector<long long>& queries) {
        int n = v.size();
        int maxi = *max_element(v.begin(),v.end());
        vector<int> freq(maxi+1,0); 
        for(int i=0; i<n; i++) freq[v[i]]++;
        vector<int> numMult(maxi+1,0);
        for(int i=1; i<=maxi; i++){
            for(int j=i; j<=maxi; j+=i){
                numMult[i]+=freq[j];
            }
        }
        vector<ll> exactPairs(maxi+1,0);
        for(int i=maxi; i>0; i--){
            ll cnt = numMult[i];
            exactPairs[i]=cnt*(cnt-1)/2;
            for(int multiple=2*i; multiple<=maxi; multiple+=i){
                exactPairs[i]-=exactPairs[multiple];
            }
        }
        
        vector<ll> prefix(maxi+1,0);
        for(int i=1; i<=maxi; i++){
            prefix[i]=prefix[i-1]+exactPairs[i];
        }
        vector<int> ans;
        for(int i=0; i<queries.size(); i++){
            int to_push = lower_bound(prefix.begin(),prefix.end(),queries[i]+1)-prefix.begin();
            ans.push_back(to_push);
        }
        return ans;
    }
};