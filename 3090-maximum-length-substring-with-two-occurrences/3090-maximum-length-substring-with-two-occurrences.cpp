class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26]={0};
        int left=0,max_len=0;
        for(int right=0;right<s.length();right++){


            int char_idx = s[right] - 'a';
            freq[char_idx]++;
            
           
            while (freq[char_idx] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }
            
            // Mathematical length calculation (No Data/String copying)
            max_len = max(max_len, right - left + 1);
        }return max_len;
    }
};