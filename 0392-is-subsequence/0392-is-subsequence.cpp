class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // Pointer for string s
        int j = 0; // Pointer for string t
        
        // Loop until we reach the end of either string
        while (i < s.size() && j < t.size()) {
            // If characters match, move the pointer in s
            if (s[i] == t[j]) {
                i++;
            }
            // Always move the pointer in t
            j++;
        }
        
        // If i reached the end of s, then s is a subsequence of t
        return i == s.size();
    }
};
