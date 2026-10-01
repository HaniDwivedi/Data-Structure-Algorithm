#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) { // Changed char* to string for C++ range-based loop
        stack<char> st;
        
        for (char c : s) {
            // 1. If it's an opening bracket, push it
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                // 2. If we see a closing bracket but stack is empty, it's invalid
                if (st.empty()) return false;
                
                char topElement = st.top();
                
                // 3. Check if the closing bracket matches the top of the stack
                if ((c == ')' && topElement == '(') || 
                    (c == '}' && topElement == '{') || 
                    (c == ']' && topElement == '[')) {
                    st.pop();
                } else {
                    return false; // Mismatched bracket type
                }
            }
        }
        
        // 4. If the stack is empty, all brackets were matched correctly
        return st.empty();
    }
};