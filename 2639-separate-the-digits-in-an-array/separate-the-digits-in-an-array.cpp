class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for(int n:nums){
            vector<int> sep;
            int temp=n;
            while(temp>0){
                sep.push_back(temp%10);
                temp/=10;
            }
            for(int i=sep.size()-1;i>=0;--i){
                result.push_back(sep[i]);
            }
        }
        return result;
    }
};