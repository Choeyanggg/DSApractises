class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int maxcount=0;
        int left=0;
        for(int right=0;right<s.length();right++){
            if(mp.find(s[right])!=mp.end()){
                left=max(left,mp[s[right]]+1);
            }
            mp[s[right]]=right;
            maxcount=max(maxcount,right-left+1);
        }
        return maxcount;
    }
};