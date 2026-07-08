class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9+7;
    ll power(ll base, ll exp){
        base%=MOD;
        ll res = 1;
        while(exp){
            if(exp%2!=0) res=(res*base)%MOD;
            base=(base*base)%MOD; 
            exp/=2;
        }
        return res%MOD;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        ll n = s.size();
        vector<ll> psum(n,0), pval(n,0), pnzero(n,0);
        psum[0]=pval[0]=s[0]-'0';
        pnzero[0]=(s[0]=='0'?0:1);
        for(ll i=1; i<n; i++){
            if(s[i]!='0'){
                psum[i]=psum[i-1]+s[i]-'0';
                pval[i]=(pval[i-1]*10+s[i]-'0')%MOD;
                pnzero[i]=pnzero[i-1]+1;
            }
            else{
                psum[i]=psum[i-1];
                pval[i]=pval[i-1];
                pnzero[i]=pnzero[i-1];
            }
        }
        vector<int> ans;
        for(ll i=0; i<queries.size(); i++){
            ll l = queries[i][0];
            ll r = queries[i][1];
            ll curr_val, curr_sum;
            if(l==0){
                curr_val = pval[r];
                curr_sum = psum[r];
            }
            else{
                ll power_term = power(10,pnzero[r]-pnzero[l-1]);
                curr_val = (pval[r]-(pval[l-1]*power_term)%MOD+MOD)%MOD;
                curr_sum = psum[r]-psum[l-1];
            }
            ans.push_back(curr_val*curr_sum%MOD);
        }   
        return ans;
    }
};