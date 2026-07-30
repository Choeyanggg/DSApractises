class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long>pq;
        for(int x: gifts){
            pq.push(x);
        }
        while(k>0){
            pq.push(floor(sqrt(pq.top())));
            pq.pop();
            k--;
        }
        long long sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};