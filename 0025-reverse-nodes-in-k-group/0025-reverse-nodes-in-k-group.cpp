class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == nullptr) return head; 
            temp = temp->next;
        }

     
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* front = nullptr;
        
        for (int i = 0; i < k; i++) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

    
        if (front != nullptr) {
            head->next = reverseKGroup(front, k);
        }

      
        return prev;
    }
};