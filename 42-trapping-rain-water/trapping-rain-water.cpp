class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int lmax=0;
        int rmax=0;
        int water=0;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]<lmax){
                    water+=lmax-height[left];
                }
                lmax=max(lmax,height[left]);
                left++;
            }else if(height[right]<=height[left]){
                if(height[right]<rmax){
                    water+=rmax-height[right];
                }
                rmax=max(rmax,height[right]);
                right--;
            }
        }return water;
    }
};