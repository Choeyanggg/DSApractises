class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> final;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int fix=nums[i];
            int start=i+1;
            int end=n-1;
            while(start<end){
                int res=fix+nums[start]+nums[end];
                if(res==0){
                    final.push_back({fix,nums[start],nums[end]});
                    start++;
                    end--;
                    while(start<end && nums[start]==nums[start-1]){
                        start++;
                    }
                }else if(res<0){
                    start++;
                }else{
                    end--;
                }
            }
        }
        return final;
    }
};