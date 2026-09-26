class Solution {
public:
    vector<int> parent;
    int find(int a){
        if(parent[a]==a) return a;
        return parent[a]=find(parent[a]);
    }
    void unite(int a, int b){
        int x=find(a);
        int y=find(b);
        if(x!=y){
            parent[x]=y;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(string s:equations){
            if(s[1]=='='){
                int a=s[0]-'a';
                int b=s[3]-'a';
                unite(a,b);
            }
        }
        for(string s:equations){
            if(s[1]=='!'){
                int a=s[0]-'a';
                int b=s[3]-'a';
                if(find(a)==find(b)) return false;
            }
        }return true;
    }
};