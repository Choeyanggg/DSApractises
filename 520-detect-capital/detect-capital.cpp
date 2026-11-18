class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allUpper=all_of(word.begin(),word.end(),[] (char c){ return isupper(c);});
        bool allLower=all_of(word.begin(),word.end(),[] (char c){ return islower(c);});
        bool upperRestlower=isupper(word[0]) && all_of(word.begin()+1,word.end(),[](char c){ return islower(c);});
        return allUpper || allLower || upperRestlower;
    }
};