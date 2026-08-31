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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
                if (head == nullptr || head->next == nullptr) {
               return nullptr;
             }

             // Pass 1: Count total nodes in the list
             int count = 0;
             ListNode* h = head;
             while (h != nullptr) {
                 count++;
                 h = h->next;
             }if (count == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
    int c = count - n;
        ListNode* curr = head;
        for (int a = 0; a < c - 1; a++) {
            curr = curr->next;
        }


             ListNode* toDelete = curr->next;
             curr->next = curr->next->next;
             delete toDelete;
             return head;

    }
};