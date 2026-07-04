class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int gascount=0, costcount=0;
        int start=0;
        for(int i=0;i<n;i++){
            gascount+=gas[i];
            costcount+=cost[i];
        }
        if(gascount>=costcount){
            int tank=0;
            for(int i=0;i<n;i++){
                tank+=gas[i]-cost[i];
                if(tank<0){
                    tank=0;
                    start=i+1;
                }
            }
            return start;
        }else return -1;
    }
};