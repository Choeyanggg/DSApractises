class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[left]==nums[mid]&& nums[mid]==nums[right]){
                left++;
                right--;
            }
            else if(nums[mid]==target){
                return true;
            }
            else if(nums[left]<=nums[mid]){
                if(target<=nums[mid] && target>=nums[left]){
                    right=mid;
                }else left=mid+1;
            }else{
                if(target<=nums[right] && target>=nums[mid]){
                    left=mid+1;
                }else right=mid;
            }
        }return (nums[left]==target);
    }
};