class Solution {
public:
    int maxRow(vector<vector<int>>& v, int j){
        int maxi=0;
        for(int i=1; i<v.size(); i++){
            if(v[i][j]>v[maxi][j]) maxi=i;
        }
        return maxi;
    }
    vector<int> findPeakGrid(vector<vector<int>>& v) {
        int m=v.size(), n=v[0].size();
        int l=0, r=n-1;
        while(r>=l){
            int mid = (r+l)/2;
            int i=maxRow(v,mid);
            int j=mid;
            if((j==0 || v[i][j]>v[i][j-1]) && (j==n-1 || v[i][j]>v[i][j+1])) return {i,j};
            if(j==0 || v[i][j]>v[i][j-1]) l=mid+1;
            else r=mid;
        }
        return {-1,-1};
    }
};