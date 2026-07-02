class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s(jewels.begin(),jewels.end());
        int count=0;
        for(char x:stones){
            if(s.count(x)) count++;
        }
        return count;
    }
};