class Solution {
public:
    bool isPalindrome(string s) {
        int start=0, end=s.length()-1;
        while(start<end){
            if(!isalpha(s[start]) && !isdigit(s[start])) start++;
            else if(!isalpha(s[end]) && !isdigit(s[end])) end--;
            else{
                if(tolower(s[start])!=tolower(s[end])){
                    return false;
                }
                start++;
                end--;
            }
        }
        return true;
    }
};