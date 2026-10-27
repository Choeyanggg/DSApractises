class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        if(s.length()==0) return 0;
        if(s.length()==1) return 1;
        mp[s[0]]++;
        int n=s.length();
        int j=0;
        int res=0;
        for(int i=1;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                while(s[j]!=s[i]){
                    mp.erase(s[j]);
                    j++;
                }
                mp.erase(s[j++]);
            }
            res=max(res,i-j+1);
            mp[s[i]]++;
        }return res;
    }
};