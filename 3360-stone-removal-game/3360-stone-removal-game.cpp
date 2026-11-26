class Solution {
public:
    bool canAliceWin(int n) {
        int a=10;
        bool turn =0;//A 

        while(n>=a){
            n-=a;
            turn =!turn ;
             a--;    
        }
        return turn ;
    }
};