class Solution {
public:
    bool dfs(int source,vector<vector<int>>& adj,vector<int>& visited,int destination){
        if(source==destination) return true;
        visited[source]=1;
        for(auto a:adj[source]){
            if(!visited[a]){
                if(dfs(a,adj,visited,destination)){
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> visited(n,0);
        return dfs(source,adj,visited,destination);
    }
};