class Solution {
public:
    vector<int>parent;
    int find(int src){
        if(parent[src]==src) return src;
        return parent[src]=find(parent[src]);
    }
    void unite(int x,int y){
        int a=find(x);
        int b=find(y);
        if(a!=b){
            parent[a]=b;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        parent.resize(n);
        for(int i=1;i<n;i++){
            parent[i]=i;
        }

        for(auto e:edges){
            if(find(e[0])==find(e[1])){
                return {e[0],e[1]};
            }unite(e[0],e[1]);
        }return {};
    }
};