class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        for(int i=0;i<=rowIndex;i++){
            vector<int> layer(i+1);
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    layer[j]=1;
                }else{
                    layer[j]=res[i-1][j-1]+res[i-1][j];
                }
            }res.push_back(layer);
        }return res[rowIndex];
    }
};