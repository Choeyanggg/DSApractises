class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for(char x:s){
            if(ans.empty() || ans.back()!=x) ans.push_back(x);
            else ans.pop_back();
        }
        return ans;
    }
};