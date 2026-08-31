class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        int i = 1;

        int firstCritIdx = -1;
        int prevCritIdx = -1;
        int minDistance = INT_MAX;

        while (curr->next) {
          
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                if (firstCritIdx == -1) {
                    firstCritIdx = i;  } else {
                  
                    minDistance = min(minDistance, i - prevCritIdx);
                }
                prevCritIdx = i;  }

            prev = curr;
            curr = curr->next;
            i++;
        }

       
        if (minDistance == INT_MAX) {
            return {-1, -1};
        }

        int maxDistance = prevCritIdx - firstCritIdx;
        return {minDistance, maxDistance};
    }
};