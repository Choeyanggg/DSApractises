class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool> &visited,int source,int destination){
        if(source==destination) return true;
        visited[source]=true;
        for(auto a:adj[source]){
            if(!visited[a]){
                if(dfs(adj,visited,a,destination)){
                    return true;
                }
            }
        }return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>visited(n,false);
        return dfs(adj,visited,source,destination);
    }
};