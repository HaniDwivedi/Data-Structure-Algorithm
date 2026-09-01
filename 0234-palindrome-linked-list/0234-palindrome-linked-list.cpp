class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        int cnt = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            cnt++;
            curr = curr->next;
        }

        int mid = cnt / 2;
        bool isOdd = (cnt % 2 != 0);

        stack<int> st;
        curr = head;
        int idx = 0;

  
        while (curr != nullptr) {
            if (idx < mid) {
              
                st.push(curr->val);
            } else if (idx == mid && isOdd) {
               
            } else {
                // Compare second half with stack top
                if (st.empty() || st.top() != curr->val) {
                    return false;
                }
                st.pop();
            }
            idx++;
            curr = curr->next;
        }

        return st.empty();
    }
};