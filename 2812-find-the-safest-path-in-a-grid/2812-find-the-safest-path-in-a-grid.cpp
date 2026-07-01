class Solution {
public:
    void riskMat(vector<vector<int>>& v, vector<vector<int>>& dist){
        int m=v.size(), n=v[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(v[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int i = top.first, j=top.second;
            if(i+1<m && dist[i+1][j]==-1) {dist[i+1][j]=dist[i][j]+1; q.push({i+1,j});}
            if(i-1>=0 && dist[i-1][j]==-1) {dist[i-1][j]=dist[i][j]+1; q.push({i-1,j});}
            if(j+1<n && dist[i][j+1]==-1) {dist[i][j+1]=dist[i][j]+1; q.push({i,j+1});}
            if(j-1>=0 && dist[i][j-1]==-1) {dist[i][j-1]=dist[i][j]+1; q.push({i,j-1});}
        }
    }
    bool poss(vector<vector<int>>& dist, int sf){
        if(dist[0][0]<sf) return false;
        int m=dist.size(), n=dist[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(m,vector<int>(n,0));
        q.push({0,0}); visited[0][0]=1;
        while(!q.empty()){
            int i=q.front().first, j=q.front().second; q.pop();
            if(i==m-1 && j==n-1) return true;
            if(i+1<m && !visited[i+1][j] && dist[i+1][j]>=sf){q.push({i+1,j}); visited[i+1][j]=1;}
            if(i-1>=0 && !visited[i-1][j] && dist[i-1][j]>=sf){q.push({i-1,j}); visited[i-1][j]=1;}
            if(j+1<n && !visited[i][j+1] && dist[i][j+1]>=sf){q.push({i,j+1}); visited[i][j+1]=1;}
            if(j-1>=0 && !visited[i][j-1] && dist[i][j-1]>=sf){q.push({i,j-1}); visited[i][j-1]=1;}
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& v) {
        if(v[0][0]==1 || v.back().back()==1) return 0;
        int m=v.size(), n=v[0].size();
        vector<vector<int>> dist(m,vector<int>(n,-1)); riskMat(v,dist);
        int l=0, r=400;
        while(r-l>1){
            int mid = (r+l)/2;
            if(poss(dist,mid)) l=mid;
            else r=mid;
        }
        return l;
    }
};