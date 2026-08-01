class Solution {
public:
    int memo[20][20];
    int helper(vector<int>& v, int l, int r, int bit){
        int n=v.size(); 
        if(l>r) return 0;
        if(memo[l][r]!=-1) return memo[l][r];
        if(bit){
            int left = v[l]+helper(v,l+1,r,!bit);
            int right = v[r]+helper(v,l,r-1,!bit);
            return memo[l][r] = max(left,right);
        }
        else{
            int left = -v[l]+helper(v,l+1,r,!bit);
            int right = -v[r]+helper(v,l,r-1,!bit);
            return memo[l][r] = min(left,right);
        }
        return 0;
    }
    bool predictTheWinner(vector<int>& v){
        memset(memo,-1,sizeof(memo));
        return helper(v,0,v.size()-1,1)>=0;
    }
};