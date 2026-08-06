class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int temp = n;
            int digitProduct = 1;

          
            while (temp > 0) {
                digitProduct *= (temp % 10);
                temp /= 10;
            }

           
            if (digitProduct % t == 0) {
                return n;
            }

            n++;
        }
    }
};