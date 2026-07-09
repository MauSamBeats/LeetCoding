class Solution {
public:
class DSU {
private:
    std::vector<int> parent;
    std::vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]); 
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            if (size[root_i] < size[root_j]) {
                std::swap(root_i, root_j);
            }
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
    }

    bool same_set(int i, int j) {
        return find(i) == find(j);
    }
    
    int get_size(int i) {
        return size[find(i)];
    }
};
    vector<bool> pathExistenceQueries(int n, vector<int>& v, int k, vector<vector<int>>& queries) {
        DSU mg(n);
        for(int i=0; i<n-1; i++){
            if(v[i+1]-v[i]<=k) mg.unite(i,i+1);
        }
        vector<bool> ans;
        for(int i=0; i<queries.size(); i++){
            int u = queries[i][0];
            int v = queries[i][1];
            ans.push_back(mg.same_set(u,v));
        }
        return ans;
    }
};