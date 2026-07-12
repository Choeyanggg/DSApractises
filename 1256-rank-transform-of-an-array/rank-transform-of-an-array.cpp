class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mp;
        vector<int> r=arr;
        int rank=1;
        sort(r.begin(),r.end());
        for(int i=0;i<r.size();i++){
            if(mp.find(r[i])!=mp.end()) continue;
            else mp[r[i]]=rank++;
        }
        for(int i=0;i<arr.size();i++){
            r[i]=mp[arr[i]];
        }
        return r;
    }
};