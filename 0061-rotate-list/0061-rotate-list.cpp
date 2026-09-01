class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge cases: list empty hai, 1 element hai, ya rotation 0 hai
        if (!head || !head->next || k == 0) return head;

        // 1. Length (n) count karein
        int n = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            n++;
            curr = curr->next;
        }

     
        k = k % n;
        if (k == 0) return head;

        // 3. New tail index (target) tak jayein
        int target = n - k;
        int idx = 1;
        curr = head;
        
        while (idx < target) {
            idx++;
            curr = curr->next;
        }

        // 4. Split point set karein: dummy new head banega
        ListNode* dummy = curr->next;
        curr->next = nullptr; // List ko yahan se break karein

        // 5. Remaining list ke end tak jaakar original head se connect karein
        ListNode* temp = dummy;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head;

        return dummy; // New head return karein
    }
};