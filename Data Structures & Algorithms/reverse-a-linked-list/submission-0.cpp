class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // 1. Store next node
            curr->next = prev;               // 2. Reverse current node's pointer
            prev = curr;                     // 3. Move prev forward
            curr = nextTemp;                 // 4. Move curr forward
        }

        return prev; // prev is now the head of the reversed list
    }
};