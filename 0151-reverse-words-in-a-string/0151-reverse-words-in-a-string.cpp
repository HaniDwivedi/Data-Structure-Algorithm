class Solution {
public:
    string reverseWords(string s) {
        // 1. Puri string ko reverse karo
        reverse(s.begin(), s.end());

        // 2. Leading spaces ko erase karo (while loop approach)
        while (!s.empty() && s.front() == ' ') {
            s.erase(s.begin());
        }

        // 3. Substrings/Words ko wapas reverse karo
        int n = s.size();
        int start = 0;

        for (int i = 0; i <= n; i++) {
           
            if (i == n || s[i] == ' ') {
                if (start < i) {
                    reverse(s.begin() + start, s.begin() + i);
                }
                start = i + 1;
            }
        }

        // 4. Middle ke extra spaces & trailing spaces clean karo
        string result = "";
        bool inSpace = false;
        
        for (char c : s) {
            if (c != ' ') {
                result += c;
                inSpace = false;
            } else if (!inSpace) {
                result += ' ';
                inSpace = true;
            }
        }

        // Agar last me extra space reh gaya ho toh use remove karo
        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};