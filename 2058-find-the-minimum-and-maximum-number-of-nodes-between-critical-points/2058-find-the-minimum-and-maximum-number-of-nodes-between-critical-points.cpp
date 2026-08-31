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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> idx; 
           
        ListNode * curr = new ListNode ();
        ListNode * prev = new ListNode ();
        prev = head ; 
        curr= head->next ;
        int i=1 ; 
        while ( curr -> next ){
           if(curr->val>prev->val&&curr ->val> curr-> next -> val|| curr->val<prev->val&&curr ->val< curr-> next -> val){
            idx.push_back(i);
           }
        i++;
        prev=curr ; 
        curr= curr-> next ;




        } 
      if (idx.size() < 2) return {-1, -1};

int mi = INT_MAX;
int ma = idx.back() - idx[0]; // Maximum distance always first & last point ke beech me hoga

// Minimum distance ke liye sirf adjacent elements check karein
for (int i = 1; i < idx.size(); i++) {
    mi = min(mi, idx[i] - idx[i - 1]);
}

return {mi, ma};

return {mi, ma};
    
    }
};