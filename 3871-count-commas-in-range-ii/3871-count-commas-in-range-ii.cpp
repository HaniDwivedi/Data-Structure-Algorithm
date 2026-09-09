class Solution {
public:
    long long countCommas(long long n) {
        long long base=1000;
        if(n<1000)return 0 ; long long cnt =0;
        while(base<=n){
cnt+=n-base+1;
base*=1000;
        }return cnt;
    }
};