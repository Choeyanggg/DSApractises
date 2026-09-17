class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        int a =find(x);
        int b =find(y);
        if(a!=b){
            parent[a]=b;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1){
                    unite(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(find(i)==i){
                count++;
            }
        }return count;
    }
};