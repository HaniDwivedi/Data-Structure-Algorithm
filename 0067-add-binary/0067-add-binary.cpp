class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int c = 0;
        string ans = "";

        while (i >= 0 || j >= 0) {
            if (i < 0) {
           
                if (c == 0 && b[j] == '0') { ans.insert(ans.begin(), '0'); c = 0; }
                else if (c == 0 && b[j] == '1') { ans.insert(ans.begin(), '1'); c = 0; }
                else if (c == 1 && b[j] == '0') { ans.insert(ans.begin(), '1'); c = 0; }
                else if (c == 1 && b[j] == '1') { ans.insert(ans.begin(), '0'); c = 1; }
            } 
            else if (j < 0) {
               
                if (a[i] == '0' && c == 0) { ans.insert(ans.begin(), '0'); c = 0; }
                else if (a[i] == '0' && c == 1) { ans.insert(ans.begin(), '1'); c = 0; }
                else if (a[i] == '1' && c == 0) { ans.insert(ans.begin(), '1'); c = 0; }
                else if (a[i] == '1' && c == 1) { ans.insert(ans.begin(), '0'); c = 1; }
            } 
            else {
               
                if (a[i] == '0' && b[j] == '0') {
                    if (c == 0) { ans.insert(ans.begin(), '0'); c = 0; }
                    else { ans.insert(ans.begin(), '1'); c = 0; }
                } 
                else if ((a[i] == '0' && b[j] == '1') || (a[i] == '1' && b[j] == '0')) {
                    if (c == 0) { ans.insert(ans.begin(), '1'); c = 0; }
                    else { ans.insert(ans.begin(), '0'); c = 1; }
                } 
                else if (a[i] == '1' && b[j] == '1') {
                    if (c == 0) { ans.insert(ans.begin(), '0'); c = 1; }
                    else { ans.insert(ans.begin(), '1'); c = 1; }
                }
            }
            i--;
            j--;
        }

        if (c == 1) {
            ans.insert(ans.begin(), '1');
        }

        return ans;
    }
};