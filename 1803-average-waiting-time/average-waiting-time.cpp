class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        double res=0;
        int finish=0;
        for(auto customer:customers){
            int arr=customer[0];
            int time=customer[1];
            finish=max(finish,arr)+time;
            res+=finish-arr;
        }return res/n;
    }
};