class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a=cost[0];
        int b=cost[1];
        int n=cost.size();
        for(int i=2;i<n;i++){
            int curr=cost[i]+min(a,b);
            a=b;
            b=curr;
        }return min(a,b);
    }
};