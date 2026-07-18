class Solution {
public:
    bool isPalindrome(string s) {
        string res="";
        string pal="";
        for(char x: s){
            if(isalpha(x) || isdigit(x)){
                x=tolower(x);
                res+=x;
                pal+=x;
            }
        }
        reverse(pal.begin(),pal.end());
        return pal==res;
    }
};