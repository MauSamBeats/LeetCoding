class Solution {
public:
    int memo[50005][2];
    bool visited[50005][2];
    int helper(vector<int>& v, int idx, int bit){
        int n=v.size(); if(idx>=n) return 0;
        if(visited[idx][bit]) return memo[idx][bit];
        if(bit){
            int take1=-1e9,take2=-1e9,take3=-1e9;
            take1 = v[idx]+helper(v,idx+1,!bit);
            if(idx+1<n) take2 = v[idx]+v[idx+1]+helper(v,idx+2,!bit);
            if(idx+2<n) take3 = v[idx]+v[idx+1]+v[idx+2]+helper(v,idx+3,!bit);
            visited[idx][bit]=1;
            return memo[idx][bit] = max(take1, max(take2, take3));
        }
        else{
            int take1=1e9,take2=1e9,take3=1e9;
            take1 = -v[idx]+helper(v,idx+1,!bit);
            if(idx+1<n) take2 = -(v[idx]+v[idx+1])+helper(v,idx+2,!bit);
            if(idx+2<n) take3 = -(v[idx]+v[idx+1]+v[idx+2])+helper(v,idx+3,!bit);
            visited[idx][bit]=1;
            return memo[idx][bit] = min(take1, min(take2, take3));
        }
        return 0;
    }
    string stoneGameIII(vector<int>& v) {
        memset(visited,0,sizeof(visited));
        int ret = helper(v,0,1);
        if(ret>0) return "Alice";
        else if(ret<0) return "Bob";
        return "Tie";
    }
};