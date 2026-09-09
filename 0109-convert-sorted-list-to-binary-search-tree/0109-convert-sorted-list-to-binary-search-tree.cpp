class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // Base cases
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return new TreeNode(head->val);

        // Slow and Fast pointers to find the middle node
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Cut the left list from the middle node
        if (prev != nullptr) {
            prev->next = nullptr;
        }

        // Create root with middle element
        TreeNode* root = new TreeNode(slow->val);

        // Recursively build left and right subtrees
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};