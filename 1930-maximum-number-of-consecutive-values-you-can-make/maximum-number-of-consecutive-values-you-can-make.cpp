class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int total=0;
        sort(coins.begin(),coins.end());
        for(int coin:coins){
            if(coin>total+1){
                break;
            }
            total+=coin;
        }return total+1;
    }
};