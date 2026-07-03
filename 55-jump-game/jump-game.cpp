class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach=0;
        int n=nums.size()-1;
        for(int i=0;i<=n;i++){
            if(i>reach) return false;
            else reach=max(reach, i+nums[i]);
        }return true;
    }
};