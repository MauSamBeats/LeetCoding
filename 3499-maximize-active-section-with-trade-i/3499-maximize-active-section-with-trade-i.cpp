class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int i=0,j=0; int maxi=0;
        int curr=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1') curr++;
        }
        while(j<n){
            if(j<=n-3 && s[j]=='0' && s[j+1]=='1'){
                j++;
                while(s[j]=='1' && j<n) j++;
                if(j>=n) break;
                else{
                    int l=i, r=j;
                    while(l>=0 && s[l]=='0') l--;
                    while(r<n && s[r]=='0') r++;
                    maxi=max(maxi,r-l-1-(j-i-1));
                }
                i=j;
            }
            else {j++; i=j;}
        }
        return curr+maxi;
    }
};