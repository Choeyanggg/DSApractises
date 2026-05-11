class Solution {
public:
    int maxArea(vector<int>& height) {
        int end=height.size()-1;
        int start=0;
        int maxi=0;
        while(start<end){
            int curr=min(height[start],height[end]);
            maxi=max(maxi,curr*(end-start));
            if(height[start]<height[end]){
                start++;
            }else{
                end--;
            }
        }
        return maxi;
    }
};