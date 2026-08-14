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
    ListNode* swapPairs(ListNode* head) {
        // ListNode* first=head;
        // ListNode* second=first->next;

        // ListNode* dummy=second;
        // second->next=first;
        // curr->next=dummy->next;
        //  swapPairs(first);
        
        
        // return head;


      

        // // Base Case: Agar list khaali hai ya sirf 1 hi node bachi hai
        // if (head == nullptr || head->next == nullptr) {
        //     return head;
        // }
        
        // // Pointers for the first two nodes
        // ListNode* first = head;
        // ListNode* second = head->next;
        
        // // Recursively swap the rest of the list and connect it to the first node
        // first->next = swapPairs(second->next);
        
        // // Swap the current pair
        // second->next = first;
        
        // // 'second' ab is sub-list ka naya head ban chuka hai
        // return second;





























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


        // 1. Base Case: Agar list khaali hai ya 1 hi node bachi hai
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // 2. Aapke pointers: first aur second
        ListNode* first = head;
        ListNode* second = head->next;
        
        // 3. Agla pair jo recursion se solve hoke aayega
        ListNode* nextPair = second->next;
        
        // 4. Proper Swapping (Jo aap karna chahte thay)
        second->next = first;
        first->next = swapPairs(nextPair); // Baki list ke liye recursive call
        
        // 5. 'second' ab is sub-list ka naya head hai
        return second;

    }

};