class Solution {
public:
    bool threeFibonacciSum(int n) {
        // Base case: smallest sum of 3 consecutive Fibonacci numbers (0 + 1 + 1)
        if (n < 2) return false; 
        
        int a = 0; // F(0)
        int b = 1; // F(1)
        int c = 1; // F(2)
        
        while (a + b + c <= n) {
            if (a + b + c == n) {
                return true;
            }
            
            // Calculate the next Fibonacci number and shift the window
            int nextFib = b + c;
            a = b;
            b = c;
            c = nextFib;
        }
        
        return false;
    }
};
