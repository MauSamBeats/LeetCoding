class Solution {
public:
    int minScore(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int> visited(n+1,0);
        queue<int> q;
        q.push(1); visited[1]=1;
        int mini = INT_MAX;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            for(auto neighbor : adj[top]){
                mini=min(mini,neighbor.second);
                if(!visited[neighbor.first]){
                    q.push(neighbor.first);
                    visited[neighbor.first]=1;
                }
            }
        }
        return mini;
    }
};