class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        vector<pair<char,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](auto& a, auto& b){return a.second>b.second;});
        string res="";
        for(auto[a,b]:v){
            while(b--){
                res+=a;
            }
        }return res;
    }
};