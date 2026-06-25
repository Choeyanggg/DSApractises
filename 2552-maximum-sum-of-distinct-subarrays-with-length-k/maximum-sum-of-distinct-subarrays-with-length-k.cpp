class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long sum=0, maxi=0;
        int j=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            mp[nums[i]]++;
        }
        if(mp.size()==k){
            maxi=sum;
        }
        for(int i=k;i<nums.size();i++){
            mp[nums[i]]++;
            mp[nums[j]]--;
            if(mp[nums[j]]==0) mp.erase(nums[j]);
            sum+=nums[i];
            sum-=nums[j];
            j++;
            if(mp.size()==k){
                maxi=max(maxi,sum);
            }
        }return maxi;
    }
};