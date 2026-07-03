class Solution {
public:
    typedef long long ll;
    bool check(vector<vector<pair<int,int>>>& adj, ll mid, ll k){
        int n = adj.size();
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> pq;
        vector<ll> dist(n,LLONG_MAX);
        pq.push({0,0}); dist[0]=0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            ll cost = top.first;
            int node = top.second;
            if(cost>k) return false;
            if(cost>dist[node]) continue;
            if(node==n-1) return true; 
            for(auto &neighbor : adj[node]){
                ll next_node = neighbor.first;
                int next_cost = neighbor.second;
                if(next_cost<mid || next_cost+cost>=dist[next_node]) continue;
                dist[next_node]=next_cost+cost;
                pq.push({next_cost+cost,next_node});
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        int l=INT_MAX, r=INT_MIN;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int cost = edges[i][2];
            if(!online[u] || !online[v]) continue;
            l=min(l,cost); r=max(r,cost);
            adj[u].push_back({v,cost});
        }
        int ans = -1;
        while(r>=l){
            int mid = (r+l)/2;
            if(check(adj,mid,k)) {ans=mid; l=mid+1;}
            else r=mid-1;
        }   
        return ans;
    }
};