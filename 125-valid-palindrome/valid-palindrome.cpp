class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return false;
        string rev;
        for(char x:s){
            if(isalpha(x) || isdigit(x)){
                x=tolower(x);
                rev+=x;
            }
        }
        string res=rev;
        reverse(res.begin(),res.end());
        return rev==res;
    }
};