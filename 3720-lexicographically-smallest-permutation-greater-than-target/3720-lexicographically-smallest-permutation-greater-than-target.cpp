class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

       
        for (int i = n - 1; i >= -1; i--) {
               vector<int> freq = count;
            bool possible = true;
            for (int k = 0; k <= i; k++) {
                if (--freq[target[k] - 'a'] < 0) {
                    possible = false;
                    break;
                }
            }
            if (!possible) continue;

                   int next_idx = i + 1;
            if (next_idx < n) {
                int start_char = target[next_idx] - 'a' + 1;
                int chosen_char = -1;
                for (int c = start_char; c < 26; c++) {
                    if (freq[c] > 0) {
                        chosen_char = c;
                        break;
                    }
                }

                if (chosen_char != -1) {
                    freq[chosen_char]--;
                    string result = target.substr(0, next_idx);
                    result += (char)('a' + chosen_char);

                    // Append remaining available characters in ascending order
                    for (int c = 0; c < 26; c++) {
                        while (freq[c] > 0) {
                            result += (char)('a' + c);
                            freq[c]--;
                        }
                    }
                    return result;
                }
            }
        }

        return "";
    }
};