class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l = 0;
        int r = 0;
        string ans = "";
        bool turn = 0;
     while (l < word1.size() && r < word2.size()) {
            ans.push_back(word1[l]);
            l++;
            ans.push_back(word2[r]);
            r++;
        }while (l < word1.size()) {
            ans.push_back(word1[l]);
            l++;
        }
        while (r < word2.size()) {
            ans.push_back(word2[r]);
            r++;
        }
                return ans;
            }
        };