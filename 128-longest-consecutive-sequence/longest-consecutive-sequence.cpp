class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int largest=0;
        for(auto a:s){
            if(s.find(a-1)==s.end()){
                int current=a;
                int seq=1;
                while(s.find(current+1)!=s.end()){
                    current++;
                    seq++;
                }
                largest=max(largest,seq);
            }
        }return largest;
    }
};