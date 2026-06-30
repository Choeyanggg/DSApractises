class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right=nums.size();
        int left=0;
        int mid=0;
        while(left<right){
            mid=left+(right-left)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) left=mid+1;
            else right=mid;
        }
        return -1;
    }
};