class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        using T=pair<int,pair<int,int>>;
        priority_queue<T,vector<T>,greater<T>> pq;
        for(int i=0;i<min((int)nums1.size(),k);i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }

        while(k-- && !pq.empty()){
            int sum=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            res.push_back({nums1[i],nums2[j]});
            if(j+1<nums2.size()){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
        }
        return res;
    }
};