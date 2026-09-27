class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int count=0;
        int res=0;
        sort(coins.begin(),coins.end());
        int i=0;
        while(count<target){
            if(i<coins.size() && coins[i]<=count+1){
                count+=coins[i];
                i++;
            }else{
                res++;
                count+=count+1;
            }
        }return res;
    }
};