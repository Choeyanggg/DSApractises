class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string res=strs[0];    
        for(int i=1;i<n;i++){
            string curr=strs[i];
            while(curr.find(res)!=0){ 
                res.pop_back();
            }
        }return res;
    }
};