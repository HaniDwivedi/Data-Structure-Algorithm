class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0;
        int p=1;
        int temp=n;
        while(temp!=0){
            s+=temp%10;
            p*=temp%10;
            temp/=10;
        }

        int t=s+p;
        if(n%t==0)return true
        ;
        else return false;

    }
};