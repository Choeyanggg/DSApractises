class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(),piles.end());
        while(k>0){
            int x=floor(pq.top()/2);
            pq.push(pq.top()-x);
            pq.pop();
            k--;
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};