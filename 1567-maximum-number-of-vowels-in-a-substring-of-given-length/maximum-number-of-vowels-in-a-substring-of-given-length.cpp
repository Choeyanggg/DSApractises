class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0;
        vector<char> vowels={'a','e','i','o','u'};
        for(int i=0;i<k;i++){
            if(find(vowels.begin(),vowels.end(),s[i])!=vowels.end()){
                count++;
            }
        }
        int maxi=count;
        for(int i=k;i<s.length();i++){
            if(find(vowels.begin(),vowels.end(),s[i])!=vowels.end()){
                count++;
            }if(find(vowels.begin(),vowels.end(),s[i-k])!=vowels.end()){
                count--;
            }maxi=max(maxi,count);
        }return maxi;
    }
};