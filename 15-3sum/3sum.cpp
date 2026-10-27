class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int first=nums[i];
            int left=i+1;
            int right=n-1;
            while(left<right){
                if(nums[left]+nums[right]==-first){
                    res.push_back({first,nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }else if(nums[left]+nums[right]>-first){
                    right--;
                }else{
                    left++;
                }
            }
        }return res;
    }
};