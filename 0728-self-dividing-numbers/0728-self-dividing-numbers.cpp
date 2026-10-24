class Solution {
public:
    bool check ( int num ){int n =num;
        while(n!=0){
            int temp =n%10;
            if(temp==0)return 0;
            else if( num%temp!=0)return 0;
            n/=10;
        }
        
        return 1;
    }


    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;  
          for( int i =left;i<=right;i++){
                if(check(i))ans.push_back(i);
          }
          return ans;

        
    }
};