class Solution {
public:
    string minWindow(string s, string t) {
        if(!s.length() || !t.length()) return "";
        int n=t.length();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){ //counting each val in t
            mp[t[i]]++;
        }
        int minLength=INT_MAX; //min length
        int j=0; //check from start
        int start=0; //actual start from where the min length start
        int required=0; //if in s, it has all the required t in it
        for(int i=0;i<s.length();i++){ // so we go in s
            if(mp[s[i]]>0){ //cause in hash, we all have those of in t
                required++;
            }
            mp[s[i]]--; //regardless we all decrease those that are not in t
            while(required==n){ //we check until the come thorugh extra required
                if(i-j+1<minLength){ //check if the length when all the required, is less than curr min
                    minLength=i-j+1;
                    start=j;// then set start as j for the start of min length
                }
                mp[s[j]]++;//j starts from the initial of the s, so checks for the requried again
                if(mp[s[j]]>0){ //when required is occured again
                    required-=1; //that lenght where all required is present is cut
                }j++;
            }// so then we check in the following i->n
        }
        if(minLength==INT_MAX) return "";
        return s.substr(start,minLength);
    }
};