class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int currjump=0;
        int maxjump=0;
        for(int i=0;i<nums.size()-1;i++){
            maxjump=max(maxjump,i+nums[i]);
            if(i==currjump){
                jumps++;
                currjump=maxjump;
            }
        }return jumps;
    }
};