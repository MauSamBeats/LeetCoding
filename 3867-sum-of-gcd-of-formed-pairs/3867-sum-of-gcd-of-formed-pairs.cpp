class Solution {
public:
    typedef long long ll;
    long long gcdSum(vector<int>& v) {
        int n = v.size();
        ll ans = 0;
        int maxi=0; vector<int> pgcd(n);
        for(int i=0; i<n; i++){
            maxi=max(maxi,v[i]);
            pgcd[i]=gcd(maxi,v[i]);
        }
        sort(pgcd.begin(),pgcd.end());
        int i=0, j=n-1;
        while(i<j){
            ans+=gcd(pgcd[i],pgcd[j]);
            i++; j--;
        }
        return ans;
    }
};