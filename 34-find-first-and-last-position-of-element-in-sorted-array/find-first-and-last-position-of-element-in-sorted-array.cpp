class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res(2,-1);
        int left=0, right=nums.size();
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                res[0]=mid;
                right=mid;
            }else if(nums[mid]>target){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        left=0, right=nums.size();
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                res[1]=mid;
                left=mid+1;
            }else if(nums[mid]<target){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return res;
    }
};