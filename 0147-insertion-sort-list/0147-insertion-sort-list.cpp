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
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* dummy = new ListNode(0);
        ListNode * curr=head;
        while(curr!=nullptr){
            ListNode* nextnode=curr->next;
            ListNode* pre=dummy;
            while(pre->next!=nullptr&&pre->next->val<curr->val){pre=pre->next;}

            curr->next=pre->next;
            pre->next=curr;
        curr=nextnode;
        }

        return dummy->next;

    }
};