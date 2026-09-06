#include <string>
#include <vector>

class Solution {
private:
    int solve(int i, int j, const std::string& s, const std::string& t, std::vector<std::vector<int>>& memo) {
        // Base case: agar target string 't' poori match ho gayi
        if (j == 0) return 1;
        // Agar source string 's' khatam ho gayi par 't' bachi hai
        if (i == 0) return 0;

        if (memo[i][j] != -1) return memo[i][j];

        if (s[i - 1] == t[j - 1]) {
            // Choice 1: Include matching character + Choice 2: Exclude current s character
            return memo[i][j] = solve(i - 1, j - 1, s, t, memo) + solve(i - 1, j, s, t, memo);
        } else {
            // Exclude current s character
            return memo[i][j] = solve(i - 1, j, s, t, memo);
        }
    }

public:
    int numDistinct(std::string s, std::string t) {
        int m = s.length(), n = t.length();
        std::vector<std::vector<int>> memo(m + 1, std::vector<int>(n + 1, -1));
        return solve(m, n, s, t, memo);
    }
};




















/*************Recursion with Decision Tree / Subset Generation/BAckTracking************/

// private:
//     // Custom Node structure for building the recursion/decision tree
//     struct Node {
//         std::string val;
//         Node* left;
//         Node* right;
//         Node() : val(""), left(nullptr), right(nullptr) {}
//     };

//     void generate(Node* root, const std::string& s, int i, const std::string& target) {
//         if (i >= s.size() || !root) return;

//         // Create left child (include character s[i])
//         if (!root->left) root->left = new Node();
//         root->left->val = root->val + s[i];

//         // Create right child (exclude character s[i])
//         if (!root->right) root->right = new Node();
//         root->right->val = root->val;

//         // Recurse down the tree
//         generate(root->left, s, i + 1, target);
//         generate(root->right, s, i + 1, target);
//     }

//     int isSame(Node* root, const std::string& target) {
//         if (!root) return 0;

//         // If leaf or current node's string matches target, count it as 1
//         int match = (root->val == target) ? 1 : 0;

//         int l = isSame(root->left, target);
//         int r = isSame(root->right, target);

//         return match + l + r;
//     }

// public:
//     int numDistinct(std::string s, std::string t) {
//         Node* root = new Node();
//         generate(root, s, 0, t);
//         return isSame(root, t);
//     }
// };