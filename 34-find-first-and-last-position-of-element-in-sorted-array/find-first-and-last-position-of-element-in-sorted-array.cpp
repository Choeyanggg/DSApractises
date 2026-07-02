class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res {-1,-1};
        int left=0, right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                res[0]=mid;
                right=mid-1;
            }else if(nums[mid]>target){
                right=mid-1;
            }else left=mid+1;
        }
        if(res[0]==-1) return res;

        left=0, right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                res[1]=mid;
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid-1;
            }else left=mid+1;
        }
        return res;
    }
};