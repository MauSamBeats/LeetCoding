class Solution {
public:
    class DSU{
        private:
            vector<int> rank;
            vector<int> parent;
        public:
            DSU(int n){
                rank.resize(n,0);
                parent.resize(n);
                for(int i=0; i<n; i++) parent[i]=i;
            }
            int findUpar(int u){
                if(parent[u]==u) return u;
                return parent[u]=findUpar(parent[u]);
            }
            void unite(int u, int v){
                int uU=findUpar(u);
                int uV=findUpar(v);
                if(uU==uV) return;
                if(rank[uU]>rank[uV]) parent[uV]=uU;
                else if(rank[uV]<rank[uU]) parent[uV]=uU;
                else{
                    parent[uU]=uV;
                    rank[uV]++;
                }
            }
            vector<int> getParent(){
                return parent;
            }
            bool isConnected(int u, int v){
                return findUpar(u)==findUpar(v);
            }
    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU mg(n);
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            mg.unite(edges[i][0],edges[i][1]);
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[mg.findUpar(i)].push_back(i);
        }
        int count=0;
        for(auto& it:mp){
            vector<int> curr = it.second;
            bool flag=true;
            for(int i=0; i<curr.size(); i++){
                if(adj[curr[i]].size()!=curr.size()-1){
                    flag=false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};