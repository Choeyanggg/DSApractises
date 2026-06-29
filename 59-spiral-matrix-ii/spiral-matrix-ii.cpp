class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res (n,vector<int> (n));
        int top=0,left=0,low=n-1,right=n-1;
        int no=1;
        while(top<=low && left<=right){
            vector<int> curr;
            for(int i=left;i<=right;i++){
                res[top][i]=no++;
            }top++;
            for(int i=top;i<=low;i++){
                res[i][right]=no++;
            }right--;
            if(top<low){
                for(int i=right;i>=left;i--){
                    res[low][i]=no++;
                }low--;
            }
            if(left<right){
                for(int i=low;i>=top;i--){
                    res[i][left]=no++;
                }left++;
            }
        }return res;
    }
};