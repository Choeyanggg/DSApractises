class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0.0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double maxi=sum/k;
        int left=0;
        for(int right=k;right<nums.size();right++){
            sum+=nums[right];
            sum-=nums[left++];
            maxi=max(maxi,sum/k);
        }
        return maxi;
    }
};