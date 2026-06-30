class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0, high=height.size()-1;
        int curr=0, maxi=INT_MIN;
        while(low<high){
            curr=min(height[low],height[high])*(high-low);
            maxi=max(maxi,curr);
            if(height[low]<height[high]) low++;
            else high--;
        }
        return maxi;
    }
};