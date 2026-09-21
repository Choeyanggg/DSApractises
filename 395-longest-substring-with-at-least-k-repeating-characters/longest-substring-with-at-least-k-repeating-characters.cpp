class Solution {
public:
    int solve(string s, int left, int right, int k){
        unordered_map<char,int> mp;
        for(int i=left;i<right;i++){
            mp[s[i]]++;
        }
        for(int i=left;i<right;i++){
            if(mp[s[i]]<k){
                int leftpart=solve(s,left,i,k);
                int rightpart=solve(s,i+1,right,k);
                return max(leftpart,rightpart);
            }
        }return right-left ;
    }

    int longestSubstring(string s, int k) {
        return solve(s,0,s.size(),k);
    }
};