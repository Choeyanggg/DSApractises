class Solution {
public:
    int findComplement(int num) {
        int comp=0;
        int temp=num;
        while(temp>0){
            comp=(comp<<1)| 1;
            temp>>=1;
        }
        return num^comp;
    }
};