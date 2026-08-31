/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        // Pass 1: Count total nodes in the list
        int count = 0;
        ListNode* h = head;
        while (h != nullptr) {
            count++;
            h = h->next;
        }
 int c=(count/2)-1;
         int a=0;
           ListNode* curr = head;
     for (int a = 0; a <c; a++) {
            curr = curr->next;
        } 


        ListNode* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;
        return head;
    }
};