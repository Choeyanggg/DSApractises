class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=INT_MIN;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            if(height[right]>height[left]){
                maxi=max(maxi,height[left]*(right-left));
                left++;
            }
            else if(height[left]>height[right]){
                maxi=max(maxi,height[right]*(right-left));
                right--;
            }else{
                maxi=max(maxi,height[left]*(right-left));
                left++;
                right--;
            }
        }return maxi;
    }
};