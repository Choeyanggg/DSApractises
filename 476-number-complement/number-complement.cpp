class Solution {
public:
    int findComplement(int num) {
        int binary[32];
        int i=0;
        while(num>0){
            binary[i++]=num%2;
            num/=2;
        }
        int arr[i];
        int k=0;
        for(int j=i-1;j>=0;j--){
            if(binary[j]){
                arr[k++]=0;
            }else{
                arr[k++]=1;
            }
        }
        int result=0;
        for(int j=0;j<i;j++){
            result<<=1;
            result|=arr[j];
        }
        return result;
    }
};