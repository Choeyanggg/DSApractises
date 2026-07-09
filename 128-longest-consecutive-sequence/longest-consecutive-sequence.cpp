class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=1;
        int curr=1;
        if(n==1) return 1;
        if(n==0) return 0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]==1){
                curr++;
                maxi=max(maxi,curr);
            }else if(nums[i]-nums[i-1]==0){
                continue;
            }else{
                
                curr=1;
            }
        }return maxi;
    }
};