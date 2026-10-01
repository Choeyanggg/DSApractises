class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> count(n+1,0);
        int curr=rounds[0];
        count[curr]++;
        for(int i=1;i<rounds.size();i++){
            while(curr!=rounds[i]){
                curr++;
                if(curr>n){
                    curr=1;
                }
                count[curr]++;
            }
        }
        vector<int> res;
        int maxi=*max_element(count.begin(),count.end());
        for(int i=1;i<=n;i++){
            if(count[i]==maxi){
                res.push_back(i);
            }
        }return res;
    }
};